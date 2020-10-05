#include<bits/stdc++.h>
// author : @akashksinghal
// Akash Kumar Singhal
using namespace std;

#define N 1000000

vector<int> A[N]; // This is adjacency list of graph
vector<int> dep(N); // It contains the depth of all vertices from the the initial passed vertex 
bool vis[N]; // Initially All nodes are not visited hence every element i.e. V[i] = false

//General DFS
void dfs(int vertex)
{
    vis[vertex]=true;
    cout << vertex << ' ';
    for(auto i: A[vertex]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

//DFS with depth
void dfs(int vertex, int depth)
{
    vis[vertex]=true;
    dep[vertex]=depth;
    for(auto i: A[vertex]){
        if(!vis[i]){
            dfs(i,depth+1);
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
       4 6
       1 2
       3 4
       2 3
       0 1
       1 0
       2 4
    */
    cout << "Depth First Traversal in starting from vertex 0 : " ;
    dfs(0);
    return 0;
}