"""Author : prajwal-naik
Question details: #38 (https://leetcode.com/problems/count-and-say/)
Time complexity: O(n^3)"""

def countAndSay(self, n: int) -> str:
    l = []
    num = "1"
    for i in range(1, n):
        l =[]
        len_num = len(num)
        j = 0
        while j < len_num:
            key = num[j]
            k = j
            count = 0
            while ((k < len_num) and (num[k] == key)):
                count += 1
                k += 1
            j = k
            l.append([count, key])
        num = ""
        for i in l:
            num += (str(i[0]) + i[1])
    return num
                
                    
            
        