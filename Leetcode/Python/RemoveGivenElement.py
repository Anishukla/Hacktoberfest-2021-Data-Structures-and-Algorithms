class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        indexCount = 0
        
        while(indexCount < len(nums)):
            if nums[indexCount] == val:
                del nums[indexCount]
            else:
                indexCount +=1
        return len(nums)