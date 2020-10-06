"""
This contains two implementations of Fibonacci Sequence by using recursivity
The first implementation is a bad one because it uses recursivity in a bad way
by computing the same values many times. The complexity of this implementation
is exponential: O(2^n)
The second implementation uses recurcive calls in a smart way to avoid redondancies.
The complexity of this implementation is linear: O(n).
"""
def bad_ﬁbonacci(n):
    #Return the nth Fibonacci number.
    if n <=1:
        return n
    else:
        return bad_ﬁbonacci(n−2) + bad_ﬁbonacci(n−1)

def good_ﬁbonacci(n):
    #Return pair of Fibonacci numbers, F(n) and F(n-1).
    if n <=1:
        return (n,0)
    else:
        (a, b) = good_ﬁbonacci(n−1)
        return (a+b, a)
