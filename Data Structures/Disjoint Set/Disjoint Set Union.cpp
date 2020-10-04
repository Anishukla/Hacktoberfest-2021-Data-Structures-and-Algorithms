template<typename t> 
class DisjointSet {
public:
    vector<t> dsu, SIZE;
    // dsu array stores the number of parent node of element.
    // Initially each node is parent of itself.
    // SIZE array stores the SIZE of the connnected component.
    // Initially SIZE of each connected commponents is one.

    // 'init' function initializes required arrays 'dsu' and 'SIZE' with initial values.

    DisjointSet(t n) {
        // n is total number of nodes.
        dsu.resize(n + 1);
        SIZE.assign(n + 1, 1);
        iota(dsu.begin(), dsu.end(), 0);
    }

    // 'root' function finds root of the disjoint set.
    t root(t a) {
        // a is node whose root we are finding.
        return dsu[a] == a? a: dsu[a] = root(dsu[a]);
    }

    // join function connects two given nodes joining two different connnected commponents.
    void join(t a, t b) {
        // a and b are nodes to be connnected.
        a = root(a);
        b = root(b);
        if (a == b) return; // a and b are already part of same connected component.
        if (SIZE[a] < SIZE[b]) dsu[a] = b, SIZE[b] += SIZE[a];
        else dsu[b] = a, SIZE[a] += SIZE[b];
    }
};
