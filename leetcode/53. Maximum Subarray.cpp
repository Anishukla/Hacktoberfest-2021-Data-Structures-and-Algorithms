// https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum =nums[0];
        int max_sum = nums[0];
        for(int i=1;i<nums.size();i++){
            current_sum = max(current_sum + nums[i], nums[i]);
            max_sum = max(max_sum, current_sum);
        }
        return max_sum;
    }
};