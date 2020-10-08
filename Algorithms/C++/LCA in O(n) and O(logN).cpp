/* By Shashank Gupta (Github , Codeforces , Codechef and Atcoder Handle - Shashank2409) */

/* This algorithm is used to find Lowest Common Ancestor of 2 nodes in a tree by 2 Methods :-
        1. Naive Method - Time complexity = O(n)
        2. Segment trees - Time complexity = O(logN)
    The above time complexity is for processing 1 query which consists of 2 nodes. A pre-processing time equaivalent to DFS time is
    required for the Euler Tour.    
 */

#include<bits/stdc++.h>
using namespace std;
const long long MAX_NO = 1e9 + 7 , maxS = 1e5+5;
int segm[4*maxS][2];

void eulerTour(int i , vector<int> graph[] , vector<int> &eulerList , vector<int> &height , int &currHeight){
	eulerList.push_back(i);
	height.push_back(currHeight);
	for(int j = 0; j < graph[i].size(); j++){
		eulerTour(graph[i][j] , graph , eulerList , height , ++currHeight);
		currHeight--;
		eulerList.push_back(i);
	    height.push_back(currHeight);
	}
}

int NaiveLCA(int node1 , int node2 , int *first , vector<int> &height , vector<int> &eulerList){
	int from = first[node1] , to = first[node2] , ancestor = 0 , miniHeight = MAX_NO;
	if(from > to) swap(from , to);
	for(int i = from; i <= to; i++){
		if(height[i] < miniHeight){
			miniHeight = height[i];
			ancestor = eulerList[i];
		}
	}
	
	return ancestor;
}

void buildSegmentTree(int pos , vector<int> &height , vector<int> &eulerList , int l , int r){
	if(l == r){
		segm[pos][0] = height[l] , segm[pos][1] = eulerList[l];
		return ; 
	}
	
	int mid = (l + r) / 2;
	buildSegmentTree(2*pos , height , eulerList , l , mid);
	buildSegmentTree(2*pos + 1 , height , eulerList , mid + 1 , r);
	
	if(segm[2*pos][0] < segm[2*pos + 1][0]){
	    segm[pos][0] = segm[2*pos][0];
	    segm[pos][1] = segm[2*pos][1];
	}
	else{
	    segm[pos][0] = segm[2*pos + 1][0];
	    segm[pos][1] = segm[2*pos + 1][1];
	}
}

void getMinimum(int pos , int queryL , int queryR , int l , int r , int &miniHeight , int &index){
	if(l > queryR || r < queryL){
		return ;
	}
	if(l >= queryL && r <= queryR){
		if(miniHeight > segm[pos][0]){
			miniHeight = segm[pos][0];
			index = segm[pos][1];
		}
		return ;
	}
	int mid = (l + r) / 2;
	getMinimum(2*pos , queryL , queryR , l , mid , miniHeight , index);
	getMinimum(2*pos + 1 , queryL , queryR , mid + 1 , r , miniHeight , index);
}

int main(){
	long long nodes;
	cin>>nodes;
	
	vector<int>graph[nodes+1];
	for(int i = 0; i < nodes - 1; i++){
		int u , v;
		cin>>u>>v;
		graph[u].push_back(v);
	}
	vector<int>eulerList , height;
	int currHeight = 0;
	eulerTour(1 , graph , eulerList , height , currHeight);
	
	int first[nodes + 1];
	memset(first , -1 , sizeof(first));
	for(int i = 0; i < eulerList.size(); i++)
		if(first[eulerList[i]] == -1)
			first[eulerList[i]] = i;
	
	int queries;
	cin>>queries;
	buildSegmentTree(1 , height , eulerList , 0 , eulerList.size() - 1);
	
	while(queries -- ){
		int node1 , node2;
		cin>>node1>>node2;
		
		/* Computing using 
			1. Naive method - O(n)
			2. Square root decomposition - O(sqrt(N))
			3. Segment Tree - O(logN)
		*/
		
		int ancestor;
		
		ancestor = NaiveLCA(node1 , node2 , first , height , eulerList);
		
		int index = -1 , miniHeight = MAX_NO , queryL = first[node1] , queryR = first[node2];
		if(queryL > queryR) swap(queryL , queryR);
		getMinimum(1 , queryL , queryR , 0 , eulerList.size() - 1 , miniHeight , index);
		ancestor = index;
		
		cout<<ancestor<<endl;
	}
}