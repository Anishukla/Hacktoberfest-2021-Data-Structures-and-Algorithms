/*
Longest consecutive subsequence 

Medium Accuracy: 48.9% Submissions: 84391 Points: 4

Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the 
consecutive numbers can be in any order.
 

Example 1:

Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
Example 2:

Input:
N = 7
a[] = {1,9,3,10,4,20,2}
Output:
4
Explanation:
1, 2, 3, 4 is the longest
consecutive subsequence.

Your Task:
You don't need to read input or print anything. Your task is to complete the function findLongestConseqSubseq() which takes the array arr[] and the 
size of the array as inputs and returns the length of the longest subsequence of consecutive integers. 


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).


Constraints:
1 <= N <= 105
0 <= a[i] <= 105
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
     int n; cin>>n; int s[n],c=0,mx=0,h[100001]={0};
     for(int i=0;i<n;i++) {cin>>s[i]; h[s[i]]++;}
     for(int i=0;i<100001;i++)
     {
         if(h[i+1]>0&&h[i]>0) {c++; mx=max(mx,c);}
         else c=0;
     }
     cout<<mx+1<<endl;
    }
	return 0;
}
