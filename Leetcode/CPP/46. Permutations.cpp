//https://leetcode.com/problems/permutations/
//Solved using backtracing approach

class Solution {
public:
    //Utility function
    void permutationUtil(vector<vector<int>>&ans,vector<int>&nums,int n,int start){
        if(start==n){
            ans.push_back(nums);
            return;
        }
        for(int i=start;i<n;i++){
            swap(nums[i],nums[start]);
            permutationUtil(ans,nums,n,start+1);
            swap(nums[i],nums[start]);
        }
    }

    //main function
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>v;
        int start=0;
        permutationUtil(ans,nums,n,start);
        return ans;
        
    }
};