/*Merge K sorted Arrays 
Contributed by Khushi Shukla
2nd October 2021
Time Complexity of the code - O(N Log k)
Approach:
1. Create a min heap that stores pair.
2. The first position of pair will have the array value and the second position will have index of the array
3. Add the first element of all the arrays and array number in the min heap.
4. Pop element from the min heap and store it in the answer vector and then insert another value in the min heap.
5. To store the values in the heap from the array we need to track the indices of the array.
*/
#include<iostream>
#include<queue>
#include<utility>
#include<vector>
//defining macros for cleaner code
#define pii pair<int, int>
#define ff first 
#define ss second
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

int main(){
    //total number of arrays
    int k;
    cin>>k;

    //2d vector
    vector<vector<int>> a(k);

    //input all the arrays
    rep(i,0,k){
        int n;
        cin>>n;
        a[i]=vector<int>(n);
        rep(j,0,n){
            cin>>a[i][j];
        }
    }


    //min heap
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    rep(i,0,k){
        pq.push({a[i][0],i});
    }

    //result vector
    vector<int> ans;

    //to track the indices
    vector<int> idx(k,0);

    //merging the sorted vectors
    while(!pq.empty()){
        auto x=pq.top(); 
        pq.pop();
        ans.push_back(x.ff);
        if(idx[x.ss]+1<a[x.ss].size()){
            pq.push({a[x.ss][idx[x.ss]+1], x.ss});
        }
        idx[x.ss]+=1;
    }

    //outputs the result vector
    rep(i,0,ans.size()){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}

/*
Expected Input:
an integer denoting total number of arrays
for each array - an integer denoting the size of array
                 the array

Expected Output:
A sorted merged array in one line

Sample Input:
3
3
1 4 6
2
2 3
3
5 6 7

Sample Output:
1 2 3 4 5 6 6 7

*/