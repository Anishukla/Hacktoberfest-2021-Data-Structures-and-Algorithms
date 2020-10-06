/*

Created on : 2020-10-03 21:57:35
@author    : archit nitin latkar

Fenwick Tree: aka Binary Indexed Tree
-> Useful for range sum queries
-> Each node is responsible for a range of nodes indicated by the Least Bit set to 1 in the index
-> Range Sum query -> O(log(n))
-> Point Update -> O(log(n))
*-> Does not support insertion of new elements

*/

#include<iostream>
#include<bits/stdc++.h>
#include<math.h>

#define INF INT_MAX
#define LOW INT_MIN

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

// void solve(){

// }
class FenwickTree{
    public:
    vector<int> tree; // the tree is an array indexed from 1
    int length; // fenwick tree has fixed length
    FenwickTree(vector<int> arr){
        tree.push_back(0); // dummy element, our array starts at index 1
        for(int i=0; i<arr.size(); i++){
            tree.push_back(arr[i]);
        }
        length = arr.size();
        for(int i=1;i<= length; i++){
            int x = log2(i & -i)+1; // find parent of index i using this.
            int j = x+i; // j is parent of i
            if(j < length){
                tree[j] += tree[i]; 
            }
        }
    }

    int prefix_sum(int index){
        int sum = 0;
        // calculates sum till the given index
        // take the node + the parent responsible for the one below it and so on ... till you reach 0
        while(index > 0){
            sum += tree[index];
            index -= (int)log2(index & -index)+1;
        }
        return sum;
    }
    void point_update(int i, int x){
        // x is new value at index i, we must add the difference to all concerned nodes
        int diff = tree[i]-x;
        while(i<length){
            tree[i] += diff;
            i += (int)log2(i & -i)+1;
        }
    }

    int range_sum(int i,int j){
        // sum from index i to j is simply the difference of their prefix sums
        return prefix_sum(j)-prefix_sum(i-1);
    }
};

int main(){ // for testing purposes
    vector<int> arr{1, 4, -3, 2, 10, 11, 13};
    FenwickTree ft(arr);
    // prefix sum for index 4
    cout<<"prefix sum for index 4 = "<<ft.prefix_sum(4)<<endl;
    // sum from index 3 to index 5
    cout<<"range sum index 3 to 5 = "<<ft.range_sum(3,5)<<endl;
    
    return 0;
}
