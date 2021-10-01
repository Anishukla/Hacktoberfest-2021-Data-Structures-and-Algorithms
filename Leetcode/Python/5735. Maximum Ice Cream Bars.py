'''
5735. Maximum Ice Cream Bars
Author: Ayushi Rawat
'''

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        a=0
        cnt=0
        for c in costs:
            a+=c
            if a<=coins:
                cnt+=1
            else:
                break
        return cnt

