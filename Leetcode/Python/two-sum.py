class Solution:
    def twoSum(self, target: int):->List[int]:
        for i in range(len(nums)):
            for j range(i+1,len(nums)):
                sum=nums[i]+nums[j]
                if sum==target:
                    return [i,j]
