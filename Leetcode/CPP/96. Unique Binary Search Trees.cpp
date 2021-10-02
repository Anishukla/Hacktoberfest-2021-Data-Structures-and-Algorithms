/*
    LOGIC:

    Consider dp_i:
    choose 1 as the root, we have 0 node for the left tree, i-1 for the
    right;
    choose 2 as the root, we have 1 node for the left tree, i-2 for the
    right;
    ...
    choose i as the root, we have i-1 nodes for the left tree, 0 for the
    right.

    Therefore, the recursive solution is dp_i = \sum_{j=0}^{i-1} dp_j dp_{i-j-1}
*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=(dp[j]*dp[i-j-1]);
            }
        }
        return dp[n];
    }
};
/*
    Time Complexity: O(n^2)
    Space Complexity: O(n+1)
*/