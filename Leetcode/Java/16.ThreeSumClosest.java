// Leetcode 16 - 3Sum Closest

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int minDiff = Integer.MAX_VALUE;
        for(int i = 0; i < n - 2; i++) {
            int cur = nums[i];
            int start = i + 1;
            int end = n - 1;
            while(start < end) {
                int left = nums[start];
                int right = nums[end];
                int sum = cur + left + right;
                if(sum > target) {
                    end--;
                } else if(sum < target) {
                    start++;
                } else {
                    return target;
                }
                int diff = target - sum;
                if(Math.abs(diff) < Math.abs(minDiff)) {
                    minDiff = diff;
                }
            }
        }
        return target - minDiff;
    }
}