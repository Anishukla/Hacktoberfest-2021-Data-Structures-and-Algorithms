// author : @ilimugur 
// Ilim Ugur
#include <bits/stdc++.h>

using namespace std;

typedef vector< vector< pair<int, long long> > > AdjacencyList;
const long long INFINITE = LLONG_MAX;

void prim(const AdjacencyList& adjList, AdjacencyList& mst)
{
    unsigned int n = adjList.size();
    mst.clear();
    mst.resize(n);

    vector<long long> minInclusionCost(n, INFINITE);
    vector<int> includingParent(n, -1);
    set< pair<long long, int > > priorityQueue;
    const int start = 1; // graph is assumed to be connected; can start from any vertex
    minInclusionCost[start] = 0LL;
    priorityQueue.insert(make_pair(minInclusionCost[start], start));

    while (!priorityQueue.empty())
    {
        set< pair<long long, int> >::iterator it = priorityQueue.begin();
        int u = it->second;
        long long edgeWeight = it->first;

        priorityQueue.erase(it);
        if (includingParent[u] != -1)
        {
            int v = includingParent[u];
            mst[u].emplace_back(v, edgeWeight);
            mst[v].emplace_back(u, edgeWeight);
        }
        
        const vector< pair<int, long long> >& neighbors = adjList[u];
        unsigned int numNeighbors = neighbors.size();
        for (unsigned int i = 0; i < numNeighbors; ++i)
        {
            int v = neighbors[i].first;
            edgeWeight = neighbors[i].second;
            if (minInclusionCost[v] > edgeWeight)
            {
                /*
                 *  A lower inclusion cost for v is found. Update priorityQueue entry
                 * and inclusionCost[v] accordingly.
                 */
                priorityQueue.erase(make_pair(minInclusionCost[v], v));
                minInclusionCost[v] = edgeWeight;
                includingParent[v] = u;
                priorityQueue.insert(make_pair(minInclusionCost[v], v));
            }
        }
    }
}

int main()
{
    /*
     * Sample code that uses Prim's Minimum Spanning Tree (MST) algorithm to
     * find the MST of a given connected, undirected graph.
     *
     * Input format:
     * n -> number of vertices in graph
     * m -> number of edges in graph
     * u, v, w -> pair of vertices representing an edge between `u` and `v` with a cost of w
     * (i.e., `u` and `v` are considered to be 1-indexed)
     */
    int n, m;
    cin >> n >> m;

    AdjacencyList adjList(n+1); // +1 is due to indices being 1-indexed

    for (int i=0; i < m; ++i)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adjList[u].emplace_back(v, w);
        adjList[v].emplace_back(u, w);
    }

    AdjacencyList mst;
    prim(adjList, mst);

    cout << "Printing the edges included in the MST:" << endl;
    for (int u = 1; u <= n; ++u)
    {
        const vector< pair<int, long long> >& neighbors = mst[u];
        unsigned int numNeighbors = neighbors.size();
        for (unsigned int j = 0; j < numNeighbors; ++j)
        {
            int v = neighbors[j].first;
            if(u < v) // To avoid printing each edge twice
            {
                long long weight = neighbors[j].second;
                cout << u << " " << v << " " << weight << endl;
            }
        }
    }


    return 0;
}

