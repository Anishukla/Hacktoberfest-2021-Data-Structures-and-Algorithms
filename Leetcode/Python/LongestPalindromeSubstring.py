def checkPalindromeFromMiddle(s:str,leftIndex:int, rightIndex:int) -> int:
    if s is None or leftIndex>rightIndex:
        return 0
        
    while(leftIndex >= 0 and rightIndex < len(s) and s[leftIndex] == s[rightIndex]):
        leftIndex-=1
        rightIndex+=1
    return rightIndex-leftIndex -1

class Solution:
       
    def longestPalindrome(self, s: str) -> str:
        startIndex = 0
        endIndex = 0
        if s is None or len(s)<1:
            return ""
        for i in range(len(s)):
            len1 = checkPalindromeFromMiddle(s,i,i)
            len2 = checkPalindromeFromMiddle(s,i, i+1)
            reqLen = len1 if len1>len2 else len2
            
            if reqLen > (endIndex -startIndex):
                startIndex = i - ((reqLen -1) //2)
                endIndex = i + (reqLen //2)
        return s[startIndex:endIndex+1]
        
    
            