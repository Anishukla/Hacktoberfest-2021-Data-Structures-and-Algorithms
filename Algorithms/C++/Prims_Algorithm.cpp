// Prim's Algorithm to find Minimum Spanning Tree in a Connected-Weighted Graph
// Time Complexity: O(n^2), where n is the number of Nodes in Graph

// Contributed by: Devanshu Yadav
// GH username: devanshuyadav

#include <bits/stdc++.h>
using namespace std;
#define SIZE 10

char alpha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
int total_weight = 0;

int MinVertex(vector<int> &Weight, vector<bool> &Visited)
{
    int vertex;
    int minimum = INT_MAX;
    for (int i = 0; i < SIZE; i++)
    {
        if (Visited[i] == false && Weight[i] < minimum)
        {
            vertex = i;
            minimum = Weight[i];
            // updated MINIMUM to check for min edge on same vertex
        }
    }
    return vertex;
}

void min_span_tree(int graph[SIZE][SIZE])
{
    int Parent[SIZE];                  // for storing MST
    vector<int> Weight(SIZE, INT_MAX); // for storing individual Weights
    vector<bool> Visited(SIZE, false); // for storing Visited vertices/nodes

    Parent[0] = -1;
    Weight[0] = 0;

    for (int i = 0; i < SIZE - 1; i++)
    {
        int best_vertex = MinVertex(Weight, Visited); // Gives Best Vertex
        Visited[best_vertex] = true;

        // Check for vertices connected to Best_vertex
        for (int j = 0; j < SIZE; j++)
        {
            // Graph(J) should exist i.e., not NULL.
            // Only the starting point is zero.
            // Graph(J) shouldn't be Visited
            // Graph(J) should be smaller than  Weight(J)

            if (graph[best_vertex][j] != 0 && Visited[j] == false && graph[best_vertex][j] < Weight[j])
            {
                Weight[j] = graph[best_vertex][j];
                Parent[j] = best_vertex;
            }
        }
    }

    // Print the final result
    // It returns the edges contributing to the Minimum Spanning Tree (along with their weights)
    for (int i = 1; i < SIZE; ++i)
    {
        cout << alpha[i] << " -> " << alpha[Parent[i]];
        cout << "  Weight = " << graph[Parent[i]][i] << "\n";
        total_weight += graph[Parent[i]][i];
    }

    // the First Node(or Starting Node)(A in this case) is omitted in the above result since it
    // is always going to be the first to visit, and it's cost will anyways be zero.
}

int main()
{
    // Input graph in form of Adjacency Matrix
    // Adjacency Matrix: skew-symmetric matrix that maps weights for every pair of nodes in the graph
    int graph[SIZE][SIZE] = {{0, 11, 3, 0, 0, 0, 10, 0, 0, 0},
                             {11, 0, 0, 4, 0, 0, 0, 0, 0, 0},
                             {3, 0, 0, 2, 12, 0, 5, 0, 0, 0},
                             {0, 4, 2, 0, 8, 0, 0, 0, 0, 0},
                             {0, 0, 12, 8, 0, 6, 0, 0, 0, 9},
                             {0, 0, 0, 0, 6, 0, 0, 5, 1, 4},
                             {10, 0, 5, 0, 0, 0, 0, 2, 0, 0},
                             {0, 0, 0, 0, 0, 5, 2, 0, 8, 0},
                             {0, 0, 0, 0, 0, 1, 0, 8, 0, 3},
                             {0, 0, 0, 0, 9, 4, 0, 0, 3, 0}};
    min_span_tree(graph);
    cout << "Total Minimum Weight: " << total_weight << endl;
    return 0;
}
