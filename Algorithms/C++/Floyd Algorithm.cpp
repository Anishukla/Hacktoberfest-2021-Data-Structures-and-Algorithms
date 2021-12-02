/*

    Floyd Algorithm is used to find the shortest path between any 2 nodes in a graph
    Type of problems:
        Given a directed or an undirected **weighted** graph, find the the shortest path between each pair of vertices i and j.

    Time Compleixty: O(N^3)

*/

const int NUMBER_OF_NODES = 100;
const int INF = 1e9; 
int d[NUMBER_OF_NODES][NUMBER_OF_NODES];

void floyd(){
    for (int k = 0; k < NUMBER_OF_NODES; ++k) { // consider k as an intermediate node between i, j
        for (int i = 0; i < NUMBER_OF_NODES; ++i) {
            for (int j = 0; j < NUMBER_OF_NODES; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
            }
        }
    }
}

int main(){

    for(int i=0;i<NUMBER_OF_NODES;i++){
        for(int j=0;j<NUMBER_OF_NODES;j++){
            d[i][j] = INF; // set distance between each pair = OO(No way to go)
        }
        d[i][i] = 0;// distance from node to itself = 0
    }

    // read you edges here i.e. set (d[i][j] = cost), for each edge in your graph
    
    floyd();
    // d[i][j] denotes shortest path to get from i to j

    return 0;
}