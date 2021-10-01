class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if strs is None or len(strs) < 1:
            return ""
        smallest = len(strs[0])
        l = []
        for x in strs:
            if len(x) < smallest:
                smallest = len(x)
        exitFlag = False
        for i in range(smallest):
            l.append(strs[0][i])
            for x in strs:
                if x[i] == l[i]:
                    continue
                else:
                    del l[i]
                    exitFlag = True
                    break
            if exitFlag:
                break
        return ''.join(l)