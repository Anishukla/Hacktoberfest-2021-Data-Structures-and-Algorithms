#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <cstring>
#include <cmath>
using namespace std;
// The C++ implementation of A* search algorithm by doraeric

const bool DEBUG = false;

class Vector3 {
public:
	float x, y, z;
	Vector3(float x, float y, float z): x(x), y(y), z(z) {}
	friend ostream& operator<< (std::ostream& stream, const Vector3& vector3);
	Vector3 operator- (Vector3 const& o) const { return { x-o.x, y-o.y, z-o.z }; }
	float length() { return sqrt(x*x + y*y + z*z); }
};

class Node {
public:
	const int id;
	const Vector3 pos;
	set<Node*> neighbors;
	Node(Vector3 pos): id(incremental_id++), pos(pos) {};
	Node(int id, Vector3 pos): id(id), pos(pos) {};
	void add_neighbor(Node * neighbor) { neighbors.emplace(neighbor); neighbor->neighbors.emplace(this); };
	void remove_neighbor(Node * neighbor) { neighbor->neighbors.erase(this); neighbors.erase(neighbor); };
	friend ostream& operator<< (std::ostream& stream, const Node& node);
	bool operator== (Node const & other) const { return id == other.id; }

private:
	static int incremental_id;
};

class PriorityNode {
public:
	float priority;
	Node const * node;
	PriorityNode(const float priority, Node const * const node): priority(priority), node(node) {};
	bool operator< (PriorityNode const& other) const { return priority < other.priority; }
	bool operator> (PriorityNode const& other) const { return priority > other.priority; }
	bool operator== (PriorityNode const & other) const { return node->id == other.node->id; }
};

template< class T, class Container = std::vector<T>, class Compare = std::greater<typename Container::value_type> >
class MyQueue : public std::priority_queue<T, Container, Compare> {
public:
	typedef typename
		std::priority_queue<
		T,
		Container,
		Compare>::container_type::const_iterator const_iterator;

	bool contrains(const T&val) const {
		auto first = this->c.cbegin();
		auto last = this->c.cend();
		while (first!=last) {
			if (*first==val) return true;
			++first;
		}
		return false;
	}
};

void a_star(const Node & start, const Node & goal, const vector<Node*> & nodes, vector<const Node *> & output) {
	const int N = nodes.size();
	// priority_queue<PriorityNode> open_set;
	MyQueue<PriorityNode> open_set;
	const Node * came_from[N];
	memset(came_from, 0, N * sizeof(Node *));
	float g_score[N];
	for (auto& g: g_score) {
		g = -1;
	}
	g_score[start.id] = 0;
	if (DEBUG) {
		for (auto& g: g_score) {
			cout << "g_score " << g << endl;
		}
	}
	float f_score[N];
	for (auto& f: f_score) {
		f = -1;
	}
	f_score[start.id] = (start.pos - goal.pos).length();
	open_set.emplace(PriorityNode(0., &start));
	while (!open_set.empty()) {
		if (DEBUG) {
			cout << "open set not empty" << endl;
		}
		PriorityNode current = open_set.top();
		open_set.pop();
		const Node * current_node = current.node;
		if (*current_node == goal) {
			if (DEBUG) {
				cout << "reach goal" << endl;
			}
			stack<const Node *> total_path;
			total_path.push(current_node);
			while (came_from[current_node->id] != NULL) {
				current_node = came_from[current_node->id];
				total_path.push(current_node);
			}
			while (!total_path.empty()) {
				output.push_back(total_path.top());
				total_path.pop();
			}
			return;
		}
		for (auto& neighbor: current_node->neighbors) {
			if (DEBUG) {
				cout << "neighbor: " << *neighbor << endl;
			}
			float tentative_g_score = g_score[current_node->id] + (current_node->pos - neighbor->pos).length();
			if (g_score[neighbor->id] < 0 || tentative_g_score < g_score[neighbor->id]) {
				came_from[neighbor->id] = current_node;
				g_score[neighbor->id] = tentative_g_score;
				f_score[neighbor->id] = tentative_g_score + (neighbor->pos - goal.pos).length();
				PriorityNode to_add(f_score[neighbor->id], neighbor);
				if (!open_set.contrains(to_add)) {
					open_set.emplace(to_add);
				}
			}
		}
	}
}

void show_map(vector<Node *> & nodes);
void show_path(vector<const Node *> & path);

int main() {
	Node start = Node(0, {0, 0, 0});
	Node mid = Node(1, {1, 0, 0});
	Node goal = Node(2, {2, 0, 0});
	Node mid2 = Node(3, {1, 1, 0});
	mid.add_neighbor(&start);
	mid.add_neighbor(&goal);
	mid2.add_neighbor(&start);
	mid2.add_neighbor(&goal);
	vector<Node *> nodes;
	nodes.push_back(&start);
	nodes.push_back(&mid);
	nodes.push_back(&goal);
	nodes.push_back(&mid2);
	cout << "Start point : " << start << endl;
	cout << "Target point: " << goal << endl;
	cout << endl;

	// 0 <-> 1 <-> 2 shortest
	// 0 <-> 3 <-> 2
	cout << "Map 1" << endl;
	show_map(nodes);
	vector<const Node *> path;
	a_star(start, goal, nodes, path);
	show_path(path);

	// 0     1 <-> 2
	// 0 <-> 3 <-> 2 the only solution
	mid.remove_neighbor(&start);
	cout << endl << "Map 2" << endl;
	show_map(nodes);
	path.clear();
	a_star(start, goal, nodes, path);
	show_path(path);

	// 0     1 <-> 2
	// 0     3 <-> 2 no solution
	mid2.remove_neighbor(&start);
	cout << endl << "Map 3" << endl;
	show_map(nodes);
	path.clear();
	a_star(start, goal, nodes, path);
	show_path(path);
	return 0;
}

int Node::incremental_id = 0;
ostream& operator<< (std::ostream& stream, const Vector3& vector3) {
	stream << "Vector3(" << vector3.x << ", " << vector3.y << ", " << vector3.z << ")";
	return stream;
}
ostream& operator<< (std::ostream& stream, const Node& node) {
	stream << "Node(" << node.id << ", " << node.pos << ")";
	return stream;
}
void show_map(vector<Node *> &nodes) {
	for (auto & node: nodes) {
		cout << *node << endl;
		for (auto & n2: node->neighbors) {
			cout << "\t" << *n2 << endl;
		}
	}
}
void show_path(vector<const Node *> & path) {
	if (path.size() > 0) {
		cout << "Find path length " << path.size() << endl;
		for (auto & node: path) {
			cout << *node << endl;
		}
	} else {
		cout << "No path found" << endl;
	}
}
