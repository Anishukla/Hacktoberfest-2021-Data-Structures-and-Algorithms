# Enter your code here. Read input from STDIN. Print output to STDOUT

from math import factorial, exp

mn = float(input())
x = int(input())
poisson_prob = ((mn ** x) * exp(-mn))/factorial(x)
print("%.3f" %poisson_prob)