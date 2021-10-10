//Submitteb by: Ananya Singh (https://github.com/AnanyaSingh2121)
//Problrm statement: https://leetcode.com/problems/unique-paths/
//Solution Code:

class Solution {
public:
  //using DP. creating a m*n matrix
    int uniquePaths(int m, int n) {
       int dp[m][n];
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++)
               dp[i][j] =  (i==0 || j==0) ? 1 : (dp[i-1][j] + dp[i][j-1]);
        }
        return dp[m-1][n-1];
        
    }
};

/*
  Space Complexity: O(m*n) (5.9 MB)
  Runtime Complexity: O(m*n) (0 ms)
*/
