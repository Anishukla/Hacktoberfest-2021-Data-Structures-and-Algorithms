class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if nums is None or len(nums)<1 :
            return 0
        
        number = nums[0]
        count = 0
        
        while(1) :
            if(count+1) >= len(nums):
                break
            
            if nums[count+1] == number:
                del nums[count]
            else:
                number = nums[count+1]
                count += 1
        
        return len(nums)
                
        
        
            