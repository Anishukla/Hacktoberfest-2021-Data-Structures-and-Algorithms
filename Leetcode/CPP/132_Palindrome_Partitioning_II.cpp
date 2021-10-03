/*
LeetCode problem link : https://leetcode.com/problems/palindrome-partitioning-ii/

Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
*/
class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        int i;
        for(i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(i=0;i<n-1;i++){
            if(s[i]==s[i+1])
                dp[i][i+1]=true;
        }
        for(i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if((j-i)>=2 && s[i]==s[j] && dp[i+1][j-1]==true)
                    dp[i][j]=true;
            }
        }
        int cuts[n];
        for(i=0;i<n;i++){
            int temp=INT_MAX;
            if(dp[0][i]==true){
                cuts[i]=0;
            }
            else{
            
            for(int j=0;j<i;j++){
                
                if(dp[j+1][i]==true && temp>cuts[j]+1){
                    temp=cuts[j]+1;
                }
            }
            
            cuts[i]=temp;
        }
    }
    
    //Return the result.    
    return cuts[n-1];
        
    }
};

/*
Sample inputs:
Input: s = "aab"
Output: 1

Input: s = "a"
Output: 0

Input: s = "ab"
Output: 1
Time Complexity: O(n*n) 
*/
