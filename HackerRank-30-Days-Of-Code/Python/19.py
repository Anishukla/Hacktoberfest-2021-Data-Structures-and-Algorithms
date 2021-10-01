class AdvancedArithmetic(object):
    def divisorSum(n):
        raise NotImplementedError

class Calculator(AdvancedArithmetic):
    def divisorSum(self, n):
        pass
        
        if n == 1:
            return 1
        else:
            factor_sum = 1 + n 
            for i in range(2, n//2 + 1):
                if n % i == 0:
                    factor_sum += i
            return factor_sum

