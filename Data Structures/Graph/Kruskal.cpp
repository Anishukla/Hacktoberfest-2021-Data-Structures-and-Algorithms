// MST is a tree which has no cycle and minimum wieghted edge

// Algo to implement MST:

//1. Sort according to wieght;
//2. Using DSU try to find that respective edge form a cycle or not if not add the edge.

#include <bits/stdc++.h>
using namespace std;
class DSU{
    int *parent;
    int *rank;
    public:
    DSU(int n){
        parent = new int[n];
        rank = new int[n];
        for(int i=0;i<n;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int find(int i){
        if(parent[i]==-1)return i;
        return parent[i]=find(parent[i]);
    }
    void unite(int x,int y){
        int s1 = find(x);
        int s2 = find(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else{
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
};
class graph{
    vector<vector<int>> edgelist;
    int V;
    public:
    graph(int V){
        this->V=V;
    }
    void addedge(int x,int y,int w){
        edgelist.push_back({w,x,y});
    }
    int algo(){
        // sorting
        sort(edgelist.begin(),edgelist.end());
        DSU s(V);
        int ans=0;
        for(auto edge: edgelist){
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];
            if(s.find(x)!=s.find(y)){
                s.unite(x,y);
                ans+=w;
            }
        }
        return ans;
    }
};
int main()
{
    graph g(4);
    g.addedge(0,1,1);
    g.addedge(1,3,3);
    g.addedge(3,2,4);
    g.addedge(2,0,2);
    g.addedge(0,3,2);
    g.addedge(1,2,2);
    cout<<g.algo();
    return 0;
}
