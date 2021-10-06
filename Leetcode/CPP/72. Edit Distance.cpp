/*
https://leetcode.com/problems/edit-distance/
Author: Sahil Rana (Rsr0)
Time Complexity: O(n*m)
Space Complexity: O(n*m) or O(501 * 501)

Solved Using Dynamic Programming (Tabulation method)
*/

class Solution {
public:
    int dp[501][501]; // dp matrix to store number of operations at (i,j).
    
    int minDistance(string word1, string word2) {
        int n=word1.size(), m=word2.size();  
      
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0)    // if length of word1 is 0
                    dp[i][j]=j;    // insert element of word2 in word1 
                else if(j==0)  // if length of word2 is 0
                    dp[i][j]=i;   // remove element of word1 
                else if(word1[i-1]==word2[j-1]) // when both characters are same
                    dp[i][j]=dp[i-1][j-1];    // skip both characters
                else{                         // when different characters
                    dp[i][j]=1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                  // add one and take minimum of insertion, deletion , replace operation
                }
            }
        }
        return dp[n][m];   // return minimum operations required to make word1 equal to word2.
    }
};
