// author : @ilimugur 
// Ilim Ugur
#include <bits/stdc++.h>

using namespace std;

typedef vector< vector< pair<int, long long> > > AdjacencyList;
const long long INFINITE = LLONG_MAX;

void floydWarshall(const AdjacencyList& adjList, vector< vector<long long> >& distances)
{
    unsigned int n = adjList.size();
    distances.clear();
    distances.resize(n);
    for(unsigned int i = 0; i < n; ++i)
    {
        distances[i].resize(n, INFINITE);
    }

    for(unsigned int u = 1; u < n; ++u)
    {
        const vector< pair<int, long long> >& neighbors = adjList[u];
        unsigned int numNeighbors = neighbors.size();
        for (unsigned int i = 0; i < numNeighbors; ++i)
        {
            int v = neighbors[i].first;
            long long edgeWeight = neighbors[i].second;
            distances[u][v] = edgeWeight;
        }
    }

    for(unsigned int i = 1; i < n; ++i)
    {
        distances[i][i] = 0;
    }

    for(unsigned int w = 1; w < n; ++w)
    {
        for(unsigned int u = 1; u < n; ++u)
        {
            // If check below ensures no overflow occurs
            if(distances[u][w] < INFINITE)
            {
                for(unsigned int v = 1; v < n; ++v)
                {
                    // If check below ensures no overflow occurs
                    if(distances[w][v] < INFINITE)
                    {
                        long long alternative = distances[u][w] + distances[w][v];
                        if(distances[u][v] > alternative)
                        {
                            // Edge relaxation
                            distances[u][v] = alternative;
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    /*
     * Sample code that uses Floyd-Warshall algorithm to find the minimum
     * distances between all pairs of vertices in an undirected graph.
     *
     * Input format:
     * n -> number of vertices in graph
     * m -> number of edges in graph
     * u, v, w -> pair of vertices representing an edge from `u` to `v` with a cost of w
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

    vector< vector<long long> > shortestDistances;
    floydWarshall(adjList, shortestDistances);

    for (int u = 1; u <= n; ++u)
    {
        for (int v = u + 1; v <= n; ++v)
        {
            cout << "Shortest distance between vertices " << u << " " << v << ": " << shortestDistances[u][v] << endl;
        }
    }


    return 0;
}

