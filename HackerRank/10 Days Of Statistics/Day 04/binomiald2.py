# Enter your code here. Read input from STDIN. Print output to STDOUT

from math import factorial

def comb(n,x):
	return factorial(n)/(factorial(x) * factorial(n-x))

def b(x,n,p):
	return comb(n,x) * (p**x) * ((1-p)**(n-x))

p,n = list(map(int, input().split()))
print(round(sum([b(i, n, p/100) for i in range(3)]),3))
print(round(sum([b(i,n,p / 100) for i in range(2, n+1)]),3))