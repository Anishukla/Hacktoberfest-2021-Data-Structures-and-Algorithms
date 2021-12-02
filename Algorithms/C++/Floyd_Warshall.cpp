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
   # As we need to find the shortest path from each node to all other nodes, it is better to represent the graph
     using adjacency matrix.
   # This algorithm is DP based as it breaks the problem down into smaller subproblems, then combines the 
     answers to those subproblems to solve the big, initial problem.
   
   # The idea is this: either the quickest path from A to C is the quickest path found so far from A to C, or 
     it's the quickest path from A to B plus the quickest path from B to C.
   # All pairs shortest path algorithm.
   # Works for weighted DG and UG.
   # Works with -ve edges as well.
   # Can detect -ve weight cycle, with one extra step in the main algorithm.
     * The graph has a negative cycle if at the end of the algorithm, the 
       distance from a vertex v to itself is -ve.
    
   # Time complexity: O(V^3) | Space complexity: O(V^2) (Can be done with O(1) space by modifying the original graph)
*/

vector<vi> floyd_warshall(vector<vi> &adj_matrix) {
    vector<vi> dist = adj_matrix;
    for (int k = 0; k < dist.size(); k++) {
        for (int i = 0; i < dist.size(); i++) {
            for (int j = 0; j < dist.size(); j++) {
                if (dist[i][k] >= INT_MAX || dist[k][j] >= INT_MAX) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i][i] < 0) return {};  // Contains a negative cycle
    }
    return dist;
}

int main() {
    int vertex_count = 4;

    vector<vi> adj_matrix = {{0, 3, INT_MAX, 5},
                             {2, 0, INT_MAX, 8},
                             {INT_MAX, 1, 0, INT_MAX},
                             {INT_MAX, INT_MAX, 2, 0}};

    vector<vi> dist = floyd_warshall(adj_matrix);
    for (int i = 0; i < vertex_count; i++) {
        for (int j = 0; j < vertex_count; j++) {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < vertex_count; i++) {
        for (int j = 0; j < vertex_count; j++) {
            cout << "Distance from " << i << " to " << j << " is " << dist[i][j] << endl;
        }
    }
    return 0;
}