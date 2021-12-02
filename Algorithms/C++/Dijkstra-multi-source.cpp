#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define MOD 1000000007
#define inf 1e18
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define printarr(arr, n) \
    for (ll i = 0; i < n; i++) cout << arr[i] << ' ';

/*
   # This algorithm is Greedy based.
   
   # This algorithm is used for finding the shortest path(as well as their costs) from multiple starting nodes to all 
     other nodes in a weighted & UD/DG.
   # The edges of the graph can be unidirectional/bidirectional.
   
   # Dijkstra’s algorithm doesn’t work for graphs with -𝒗𝒆 𝒘𝒆𝒊𝒈𝒉𝒕 𝒄𝒚𝒄𝒍𝒆𝒔, it 𝑴𝑨𝒀 give correct results for a 
     graph with -𝒗𝒆 𝒆𝒅𝒈𝒆𝒔. 
   # For graphs with negative weight edges and cycles, 𝑩𝒆𝒍𝒍𝒎𝒂𝒏–𝑭𝒐𝒓𝒅 𝒂𝒍𝒈𝒐𝒓𝒊𝒕𝒉𝒎 can be used.
     
   # This algorithm basically creates trees of shortest paths from the starting vertices, to all 
     other points in the graph.
   # Time Complexity: O(V x log(E))
*/

pair<vi, vi> multi_dijkstra(vector<vector<pii>> &graph, vi src, int n) {
    set<pii> s;
    vi dist(n + 1, INT_MAX);
    vi prev(n + 1, -1);
    for (auto it : src) {
        dist[it] = 0;
        s.insert({0, it});
    }
    while (!s.empty()) {
        // Popping the current min element from the set. First value of the pair isn't required as we can get it from the dist array. It is used in the set for getting the min index value
        int current = s.begin()->second;
        s.erase(s.begin());
        // Iterating through the neighbours of current
        for (auto it : graph[current]) {
            // Index of a neighbour
            int adj_el = it.first;
            // Weight of the edge between current and the neighbour
            int weight = it.second;
            if (dist[current] + weight < dist[adj_el]) {
                // Updating the the shorter distance along with the vertex's index in the set
                s.erase({dist[adj_el], adj_el});
                dist[adj_el] = dist[current] + weight;
                s.insert({dist[adj_el], adj_el});
                // Creating parent-child relationship for traversing through the shortest route
                prev[adj_el] = current;
            }
        }
    }
    return {dist, prev};
}

int main() {
    int n = 8;
    vector<vector<pii>> graph(n + 1);
    graph[1].pb({2, 5});
    graph[1].pb({8, 8});
    graph[1].pb({5, 9});
    graph[2].pb({4, 15});
    graph[2].pb({3, 12});
    graph[2].pb({8, 4});
    graph[3].pb({4, 3});
    graph[3].pb({7, 11});
    graph[4].pb({7, 9});
    graph[5].pb({8, 5});
    graph[5].pb({6, 4});
    graph[5].pb({7, 20});
    graph[6].pb({3, 1});
    graph[6].pb({7, 13});
    graph[8].pb({3, 7});
    graph[8].pb({6, 6});

    vi sources = {1, 2};
    pair<vi, vi> ans = multi_dijkstra(graph, sources, n);
    cout << "Final minimum distances: ";
    for (auto it : ans.first) cout << it << " ";
    cout << endl;
    cout << "Shortest path from 7 to a source is: ";
    // Since the algorithm was ran with 1 as source, so we can get shortest path for all vertexes only from 1
    int target = 7;
    while (target != -1) {
        cout << target << " ";
        target = ans.second[target];
    }
    return 0;
}