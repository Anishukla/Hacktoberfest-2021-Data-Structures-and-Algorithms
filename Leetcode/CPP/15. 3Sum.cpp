// https://leetcode.com/problems/3sum/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        set<vector<int>> ans;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left<right){
                int curr_sum = nums[i]+nums[left]+nums[right];
                if(curr_sum == 0 ){
                    ans.insert({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                }else if(curr_sum > 0){
                    right--;
                }else{
                    left++;
                }
            }
        }
        for(auto x: ans) output.push_back(x);
        return output;
    }
};