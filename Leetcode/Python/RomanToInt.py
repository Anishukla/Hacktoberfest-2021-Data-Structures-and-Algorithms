class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {
            "I" : 1,
            "V" : 5,
            "X" : 10,
            "L" : 50,
            "C" : 100,
            "D" : 500,
            "M" : 1000,
        }
        
        l = []
        
        for i in s:
            l.append(roman[i])
        
        for x in range(len(l)):
            if(x+1) < len(l):
                if l[x] < l[x+1]:
                    l[x] = l[x+1] -l[x]
                    del l[x+1]
        return sum(l)
                
        