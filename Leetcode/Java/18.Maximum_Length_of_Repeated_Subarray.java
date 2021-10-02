// 718. Maximum Length of Repeated Subarray

class Solution {
    //TC: O(n*m)
    public int findLength(int[] nums1, int[] nums2) {
        int n=nums1.length;
        int m=nums2.length;
        
        int[][] dp=new int[n+1][m+1];
        
        //Overall Max
        int omax=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    if(omax<dp[i][j]) omax=dp[i][j];
                }
            }
        }
        return omax; 
    }
}
