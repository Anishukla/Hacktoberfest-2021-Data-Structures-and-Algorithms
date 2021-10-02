#include<bits/stdc++.h>
using namespace std;


void topoSort(int u, vector<int> adj[], vector<bool> &vis, stack<int> &s) {
	vis[u] = true;
	
	for(int v : adj[u]) {
		if(!vis[v]) topoSort(v, adj, vis, s); // if unvisited
	}
	
	s.push(u);
}

int main() {
	
	int n = 6;
	
	vector<int> adj[n]; // adjacency list;
	vector<bool> vis(n, false); // to check visited nodes
	
	adj[5].push_back(2);
	adj[5].push_back(0);
	adj[4].push_back(0);
	adj[4].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(1);
	
	stack<int> s;
	
	for(int i = 0; i < n; i++) {
		if(!vis[i]) {
			topoSort(i, adj, vis, s);
		}
	}
	
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	
	return 0;
}