class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle is None or needle == "":
            return 0
        if haystack is None or haystack == "":
            return -1
        
        flag = True
        for i in range(len(haystack)):
            y = i
            for x in range(len(needle)):
                if y >= len(haystack):
                    return -1
                if needle[x] == haystack[y]:
                    y+=1
                    flag = True
                else:
                    flag = False
                    break
            if flag:
                return i
        return -1
                