// Solution By Tekane Chaitanya
// Question link :- https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] finalAns = {-1, -1};
        // find first occurence
        finalAns[0] = search(nums, target, true);
        if(finalAns[0] != -1){
            // find last occurence
            finalAns[1] = search(nums, target, false);
        }
        return finalAns;
    }
    int search(int[] nums, int target, boolean startIndex){
        int ans = -1;
        int start = 0;
        int end = nums.length - 1;
        while(start<=end){
            int mid = start + (end-start) / 2;
            if(target > nums[mid]){
                start = mid + 1;
            } else if(target < nums[mid]){
                end = mid - 1;
            } else {
                // potential answer found
                ans = mid;
                if(startIndex){
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return ans;
    }
    
}

// Time Complexity :- O(log n)
