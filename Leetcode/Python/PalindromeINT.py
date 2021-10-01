class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0 :
            return False
        
        strValue = "{}".format(x)
        
        l = len(strValue)
        
        if l%2 == 0:
            # even
            leftIndex = 0
            rightIndex = l -1
            for i in range(l//2):
                if strValue[leftIndex] == strValue[rightIndex]:
                    leftIndex +=1
                    rightIndex -=1
                    continue
                else:
                    return False
            return True
        else:
            # odd
            leftIndex = 0
            rightIndex = l -1
            for i in range((l-1)//2):
                if strValue[leftIndex] == strValue[rightIndex]:
                    leftIndex +=1
                    rightIndex -=1
                    continue
                else:
                    return False
            return True
        
        