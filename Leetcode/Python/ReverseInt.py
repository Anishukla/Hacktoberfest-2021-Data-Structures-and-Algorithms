class Solution:
    def reverse(self, x: int) -> int:
        if x > 2147483647 or x < -2147483648:
            return 0
        num = []
        if(x < 0):
            n = abs(x)
            while n != 0:
                num.append(n%10)
                n //=10
        elif(x == 0):
            return 0
        else:
            n = x
            while n != 0:
                num.append(n%10)
                n//=10
        num = num[::-1]
        reqNum = 0
        count = 1
        for m in num:
            reqNum += m * count
            count *=10
        if reqNum > 2147483647 or reqNum < -2147483648:
            return 0
        return reqNum if x >0 else reqNum - 2*reqNum
            