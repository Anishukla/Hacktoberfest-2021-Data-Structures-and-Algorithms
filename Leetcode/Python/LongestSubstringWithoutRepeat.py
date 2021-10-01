class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        highestLength = 0        
        if(len(s)< 1 or s is None):
            return 0
        if(len(s) is 1):
            return 1
        
        for x in range(len(s)):
            n = x
            l = []
            while(not(n+1 > len(s)) and s[n] not in l):
                l.append(s[n])
                n+=1
            if(len(l) > highestLength):
                highestLength = len(l)
        return highestLength