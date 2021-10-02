# include <bits/stdc++.h>
# define V 9

using namespace std;

int minDistance(int dist[], bool check[]) { 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (check[v] == false && dist[v] <= min) {
            min = dist[v];
            min_index = v; 
        } 
  
    return min_index; 
} 

void dijkstra(int graph[][V], int start) {
    bool check[V];
    int dist[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        check[i] = false;
    }
    dist[0] = 0; 
    for (int i = 0; i < V-1; i++) {
        int u = minDistance(dist, check);
        check[u] = true;
        for (int v = 0; v < V; v++) {
            if (!check[v] && graph[u][v]) {
                dist[v] = min (dist[v], dist[u] + graph[u][v]);
            }
        }
    }
    for (int i = 0; i < V; i++) {
        cout << i << "----" << dist[i] << endl;
    }
}

int main () {
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstra(graph, 0); 
  
    return 0; 
}