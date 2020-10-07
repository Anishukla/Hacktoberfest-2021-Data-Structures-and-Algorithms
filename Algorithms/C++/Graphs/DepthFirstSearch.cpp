// author : @ilimugur 
// Ilim Ugur
#include <bits/stdc++.h>

using namespace std;

typedef vector< vector<int> > AdjacencyList;

void dfs(const AdjacencyList& adjList, vector<bool>& visited, int u)
{
    visited[u] = true;

    const vector<int>& neighbors = adjList[u];
    int numNeighbors = neighbors.size();
    for(int i=0; i < numNeighbors; ++i)
    {
        int v = neighbors[i];
        if(!visited[v])
        {
            dfs(adjList, visited, v);
        }
    }
}

bool isReachable(const AdjacencyList& adjList, int s, int t)
{
    vector<bool> visited(adjList.size());
    dfs(adjList, visited, s);
    return visited[t];
}

int main()
{
    /*
     * Sample code that uses DFS to check if a vertex t on an
     * undirected graph is reachable from a node s.
     *
     * Input format:
     * n -> number of vertices in graph
     * m -> number of edges in graph
     * u, v -> pair of vertices connected by an edge
     * (i.e., `u` and `v` are considered to be 1-indexed)
     * s -> index of the node from which the traversal starts
     * t -> index of the destination node
     */
    int n, m, s, t;
    cin >> n >> m;

    AdjacencyList adjList(n+1); // +1 is due to indices being 1-indexed

    for(int i=0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        // Remove the line below to represent a graph with directed edges
        adjList[v].push_back(u);
    }

    cin >> s >> t;

    bool result = isReachable(adjList, s, t);
    cout << (result ? "Reachable" : "Not reachable") << endl;

    return 0;
}
