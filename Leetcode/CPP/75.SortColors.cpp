/*
https://leetcode.com/problems/sort-colors/
Author: Aditi Rao (aditirao7 on github)
Time Complexity: O(n)
Space Complexity: O(1) extra space
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0, mid =0, high=nums.size()-1;
	// If 0 is found at mid position swap with low so it can be at the beginning
	// If 1 is found at mid then it is at the correct position
	// If 2 is found at mid then swap with high so it can be at the end
        while(mid<=high)
        {
                if(nums[mid]==0) swap(nums[mid++], nums[low++]);
                else if(nums[mid]==1) mid++;
                else if(nums[mid]==2) swap(nums[mid], nums[high--]);
        }
    }
};
