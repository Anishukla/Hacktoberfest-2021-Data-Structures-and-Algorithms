// Leetcode 1 - Two Sum

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Long, Integer> numIndices = new HashMap<>();
        for(int i = 0; i < nums.length; i++) {
            numIndices.put(nums[i] * 1L, i);
        }
        for(int i = 0; i < nums.length; i++) {
            long first = nums[i];
            long second = target - first;
            if(numIndices.containsKey(second) && numIndices.get(second) != i) {
                return new int[]{i, numIndices.get(second)};
            }
        }
        return new int[]{};
    }
}