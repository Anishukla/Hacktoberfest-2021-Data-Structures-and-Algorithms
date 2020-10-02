"""
@author: anishukla
"""

"""Memoization: Often we can get a performance increase just by
 not recomputing things we have already computed."""
 
"""We will now use memoization for finding Fibonacci.
    Using this will not only make our solution faster but also 
    we will get output for even larger values such as 1000 whereas
    by general recursive approch calculating fibonacci of 40 
    will also take very large amount of time."""
    
def fibonacci_memoization(n, d={}):
    if n in d:
        return d[n]
    elif n == 0:
        ans = 0
    elif n == 1:
        ans = 1
    else:
        ans = fibonacci_memoization(n-1, d) + fibonacci_memoization(n-2, d)
    d[n] = ans
    return ans

print("Enter number of test cases you want: ")        
T = int(input())
for i in range(T):
    print("Input the position for fibonacci value: ")
    N = int(input())
    print("Fibonacci(%d) = " %N , fibonacci_memoization(N))