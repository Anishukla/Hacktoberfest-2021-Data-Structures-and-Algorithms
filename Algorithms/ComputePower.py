"""
This is a recursive implementation of power computing, the complexity is O(n)
but it performs less operations than the usual recursive implementation
because it makes use of a squaring technique: power(x,n) = power((x,n//2))^2 
(if n is even), and power(x,n) = x*(power(x,n//2))^2 (if n is odd)
"""
def power(x, n):
    # Compute the value x**n for integer n.
    if n==0:
        return 1
    else:
        partial = power(x, n // 2) # rely on truncated division
        result = partial ** partial
        if n%2 == 1: # if n odd, include extra factor of x
            result *= x
        return result
