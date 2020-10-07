// author : @ilimugur 
// Ilim Ugur
#include <bits/stdc++.h>

using namespace std;

typedef vector< vector< pair<int, long long> > > AdjacencyList;
const long long INFINITE = LLONG_MAX;

long long dijkstra(const AdjacencyList& adjList, int source, int destination)
{
    vector<long long> minCost(adjList.size(), INFINITE);

    /*
     * set<> is used instead of priority_queue<> to avoid
     * storing multiple nodes with different costs for
     * the same vertex.
     * 
     * As it has the functionality to find and remove
     * elements in logarithmic time, this alternative
     * does not add any asymptotical overhead to the
     * complexity of the algorithm.
     */
    set< pair<long long, int> > priorityQueue;

    minCost[source] = 0;
    priorityQueue.insert(make_pair(minCost[source], source));

    while (!priorityQueue.empty())
    {
        set< pair<long long, int> >::iterator it = priorityQueue.begin();
        int u = it->second;
        priorityQueue.erase(it);

        if (u == destination)
        {
            /*
             * Remove this if block for single-source-multiple-destination
             * shortest path problem variation.
             */
            break;
        }

        const vector< pair<int, long long> >& neighbors = adjList[u];
        unsigned int numNeighbors = neighbors.size();
        for (unsigned int i = 0; i < numNeighbors; ++i)
        {
            int v = neighbors[i].first;
            long long edgeCostUV = neighbors[i].second;
            if (minCost[v] > minCost[u] + edgeCostUV)
            {
                /*
                 *  A lower cost for v is found. Update priorityQueue entry
                 * and minCost[v] accordingly.
                 */
                priorityQueue.erase(make_pair(minCost[v], v));
                minCost[v] = minCost[u] + edgeCostUV;
                priorityQueue.insert(make_pair(minCost[v], v));
            }
        }
    }

    return minCost[destination];
}

int main()
{
    /*
     * Sample code that uses Dijkstra's algorithm to check minimum cost of
     * reaching to a vertex `t` from a vertex `s` on a directed acyclic graph.
     *
     * Input format:
     * n -> number of vertices in graph
     * m -> number of edges in graph
     * u, v, w -> pair of vertices representing an edge from `u` to `v` with a cost of w
     * (i.e., `u` and `v` are considered to be 1-indexed)
     * s -> index of the node from which the traversal starts
     * t -> index of the destination node
     */
    int n, m, s, t;
    cin >> n >> m;

    AdjacencyList adjList(n+1); // +1 is due to indices being 1-indexed

    for (int i=0; i < m; ++i)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adjList[u].emplace_back(v, w);
    }

    cin >> s >> t;

    long long result = dijkstra(adjList, s, t);
    if (result == INFINITE)
    {
        cout << "Destination not reachable from source." << endl;
    }
    else
    {
        cout << "Minimum cost from source to destination: " << result << endl;
    }

    return 0;
}

