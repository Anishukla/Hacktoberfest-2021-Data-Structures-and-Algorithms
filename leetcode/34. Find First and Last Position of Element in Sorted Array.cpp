// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    int getRange(vector<int>& nums, int target, int isLeft){
        int length = nums.size();
        int left = 0;
        int right = length-1;
        while(left<=right){
            int mid = (left + right)/2;
            if(target<nums[mid]) right = mid-1;
            else if(target>nums[mid]) left = mid+1;
            
            else{
                if(isLeft){
                    if(mid == 0 || nums[mid-1]!= target){
                        return mid;
                    }
                    else right = mid-1;
                }else {
                    if(mid == length-1 || nums[mid+1]!=target){
                        return mid;
                    }
                    else left = mid+1;
                }
            }
        }
        return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> output(2,-1);
        output[0] = getRange(nums, target, 1);
        output[1] = getRange(nums, target, 0);
        return output;
    }
};

//  vector<int> searchRange(vector<int>& nums, int target) {
//     vector<int> output(2,-1);
//     if(nums.size() == 0){
//         return output;
//     }
//     auto min = lower_bound(nums.begin(), nums.end(),target);
//     if(*min != target){
//         return output;
//     }
//     auto max = upper_bound(nums.begin(), nums.end(), target);
//     if(max == nums.end()){
//         return output;
//     }
//     output[0] = min-nums.begin();
//     output[1] = max-nums.begin()-1;
//     return output;
// }