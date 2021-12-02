'''
2012. Sum of Beauty in the Array - Medium
You are given a 0-indexed integer array nums. For each index i (1 <= i <= nums.length - 2) the beauty of nums[i] equals:

2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k <= nums.length - 1.
1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous condition is not satisfied.
0, if none of the previous conditions holds.
Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2.

Example 1:
Input: nums = [1,2,3]
Output: 2
Explanation: For each index i in the range 1 <= i <= 1:
- The beauty of nums[1] equals 2.

Example 2:
Input: nums = [3,2,1]
Output: 0
Explanation: For each index i in the range 1 <= i <= 1:
- The beauty of nums[1] equals 0.
'''

'''
Idea:
The condition for giving the score 1 is pretty straightforward but the condition for giving score 2 is tricky.
The approach to give score 2 is to keep track of the maximum element that we found in the left, 
so that we can check if our current element is greater than what we already found,
and the minimum element that is ahead of our current element, 
so that we can check that our current element is atleast smaller than the smallest element ahead of it.
'''

def sumOfBeauties(nums) -> int:
    n,sol = len(nums),0
    right_min, left_max = [0]*n, [0]*n

    cur_min = nums[n-1]
    right_min[n-1] = cur_min
    
    # making note of the minimum element that we will face ahead
    for i in range(n-2, -1, -1):
        cur_min = min(cur_min, nums[i])
        right_min[i] = cur_min

    cur_max = nums[0]
    left_max[0] = cur_max
    
    # making note of the maximum element that we already would have faced before our current element
    for i in range(1, n):
        cur_max = max(cur_max, nums[i])
        left_max[i] = cur_max

    # doing the conditions check as per the question
    for i in range(1,len(nums)-1):
        if nums[i]>left_max[i-1] and nums[i]<right_min[i+1]:
            sol += 2
        elif nums[i - 1] < nums[i] and nums[i] < nums[i + 1]:
            sol += 1
    
    return sol

def main():
    nums = [[1,2,3], [2,4,6,4], [3,2,1]]
    for num in nums:
        print(sumOfBeauties(num))

if __name__ == "__main__":
    main()