https://leetcode.com/problems/cherry-pickup/
class Solution {
public:
    int dp[51][51][51];
    int fun(vector<vector<int>>& grid,int x1,int y1,int x2,int y2) {
        if(x1==x2 and y1==y2) return grid[x1][y1];
        int ans=0;
        if(grid[x1][y1]==1) ans++;
        if(grid[x2][y2]==1) ans++;
        return ans;
        
    }
    int solve(vector<vector<int>>& grid,int x1,int y1,int x2) {
        int n=grid.size();
        int m=grid[0].size();
        int y2=x1+y1-x2;
        if(x1==n-1 and y1==m-1 and x2==n-1 and y2==m-1) return fun(grid,x1,y1,x2,y2);
        if(dp[x1][y1][x2]!=-1) return dp[x1][y1][x2];
        int ans=INT_MIN,d=fun(grid,x1,y1,x2,y2);
        if(x1+1<n and x2+1<n and grid[x1+1][y1]!=-1 and grid[x2+1][y2]!=-1) {
            ans=max(ans,solve(grid,x1+1,y1,x2+1));
        }
        if(x1+1<n and y2+1<m and grid[x1+1][y1]!=-1 and grid[x2][y2+1]!=-1) {
            ans=max(ans,solve(grid,x1+1,y1,x2));
        }
        if(y1+1<m and x2+1<n and grid[x1][y1+1]!=-1 and grid[x2+1][y2]!=-1) {
            ans=max(ans,solve(grid,x1,y1+1,x2+1));
        }
        if(y1+1<m and y2+1<m and grid[x1][y1+1]!=-1 and grid[x2][y2+1]!=-1) {
            ans=max(ans,solve(grid,x1,y1+1,x2));
        }
        if(ans==INT_MIN) return dp[x1][y1][x2]=INT_MIN;
        return dp[x1][y1][x2]=ans+d;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(grid,0,0,0);
        if(ans==INT_MIN) return 0;
        return ans;
    }
};
