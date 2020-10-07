#include<bits/stdc++.h>
// author : @akashksinghal
// Akash Kumar Singhal
using namespace std;

#define N 1000000

vector<int> A[N]; // This is adjacency list of graph
vector<int> dis(N); // It contains the distance of all vertices from the the initial passed vertex 
bool vis[N]; // Initially All nodes are not visited hence every element i.e. V[i] = false

//General BFS 
//Complexity : O(Number of Vertices + Number of Edges)
void bfs(int src) {
    queue<int> q;
    vis[src] = true;
    q.push(src);
    while (!q.empty()) {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        for (auto i : A[cur])
            if (!vis[i])
            {
                q.push(i);
                vis[i] = true;
            }
    }
}

// BFS with Distance Calculation
void bfs_distance(int src) {
    queue<int> q;
    vis[src] = true;
    dis[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int cur = q.front();
        cout << cur << ' ' << dis[cur] << '\n';
        q.pop();
        for (auto i : A[cur])
            if (!vis[i])
            {
                q.push(i);
                dis[i] = dis[cur] + 1;
                vis[i] = true;
            }
    }
}
 

int main()
{
    int vertices, edges ; // total number of vertices in the graph
    cin >> vertices >> edges;
    for (int i = 1; i <= edges ; i++)
    {
        int a, b;
        cin >> a >> b; // undirected edge from vertex a to b
        // To add an edge in the adjacency list
        A[a].push_back(b);
        A[b].push_back(a);
    }
    /* Input : 
        4 5
        3 4
        2 3
        0 1
        1 2
        2 4
    */
    cout << "Breadth First Traversal starting from vertex 3 : " ;
    bfs(3);
    /* 
       Output : Breadth First Traversal starting from vertex 3 : 3 4 2 1 0 
    */

    cout << "Breadth First Traversal with Depth to other vertices starting from vertex 2 : " ;
    bfs_distance(2);
    
    /* Output : 
        Breadth First Traversal with Depth to other vertices starting from vertex 2 : 
        2 0
        3 1
        1 1
        4 1
        0 2
    */
    return 0;
}