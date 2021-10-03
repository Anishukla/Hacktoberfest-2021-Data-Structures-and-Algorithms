// Leetcode 15 - 3Sum

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> output = new ArrayList<>();
        int n = nums.length;
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            searchPairs(nums, -nums[i], i + 1, output);
        }
        return output;
    }
    
    private void searchPairs(int[] nums, int target, int start, List<List<Integer>> output) {
        int end = nums.length - 1;
        while(start < end) {
            int sum = nums[start] + nums[end];
            if(sum > target) {
                end--;
            } else if(sum < target) {
                start++;
            } else {
                List<Integer> triplet = new ArrayList<>();
                triplet.add(-target);
                triplet.add(nums[start]);
                triplet.add(nums[end]);
                output.add(triplet);
                start++;
                end--;
                while(start < end && nums[start] == nums[start - 1]) {
                    start++;
                }
                while(start < end && nums[end] == nums[end + 1]) {
                    end--;
                }
            }
        }
    }
}