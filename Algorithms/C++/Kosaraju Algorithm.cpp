/* By Shashank Gupta (Github , Codeforces , Codechef and Atcoder Handle - Shashank2409) */

/* Kosaraju Algorithm is used for finding all the strongly connected components in a graph. It uses simple DFS for it's implementation
so it's time complexity is the same as that of a DFS in a graph which is O(V + E) where V = no of nodes and E = no of edges. */

#include<bits/stdc++.h>
using namespace std;
const int maxS = 1e5+5;
bool vis[maxS] , visT[maxS];

void dfsTransposed(int i , vector<int>graphT[] , vector<int>&path){
	if(visT[i])
		return ;
	path.push_back(i);
	visT[i] = true;
	for(int j = 0; j < graphT[i].size(); j++)
		dfsTransposed(graphT[i][j] , graphT , path);
}

void dfs(int i , vector<int>graph[] , stack<int> &st){
	if(vis[i] == true)
		return ;
	vis[i] = true;
	for(int j = 0; j < graph[i].size(); j++)
		dfs(graph[i][j] , graph , st);
	st.push(i);
}

void printPaths(vector<vector<int> >stronglyConnComp){
	for(int i = 0; i < stronglyConnComp.size(); i++){
		vector<int> path = stronglyConnComp[i];
		for(auto j : path)
			cout<<j<<" ";
		cout<<"\n";
	}
}

int main(){
    cout<<"Enter the no of nodes and nod of edges in your graph/n";
	/* n = no of nodes , m = no of edges */
	int n , m;
	cin>>n>>m;
	
	/* Directed graph */
	vector<int> graph[n + 1] , graphT[n + 1];
    cout<<"Enter "<<m<<" pairs which are connected through an edge\n";
	for(int i = 0; i < m; i++){
	    /* 1 <= u , v <= n */
		int u , v;
		cin>>u>>v;
		graph[u].push_back(v);
 		/* Transposed graph */
		graphT[v].push_back(u);
	}
	
	stack<int>st;
	for(int i = 1; i <= n; i++)
		dfs(i , graph , st);

	vector<vector<int> >stronglyConnComp;
	while(st.size()){
		int temp = st.top();
		st.pop();
		vector<int> path ;
		dfsTransposed(temp , graphT , path);
		if(path.size())
			stronglyConnComp.push_back(path);
	}
	
	/* For single nodes */
	for(int i = 1; i <= n; i++){
		if(!visT[i]){
		    vector<int>path(1,i);
			stronglyConnComp.push_back(path);
		}
	}
	
    printPaths(stronglyConnComp);
	
}
