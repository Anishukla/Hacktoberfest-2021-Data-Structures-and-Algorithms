# Enter your code here. Read input from STDIN. Print output to STDOUT

import math

x = int(input())
n = int(input())
mu = int(input())
sig = int(input())

muSum = n * mu
sigSum = math.sqrt(n) * sig

def cdf (x,mu, sig) :
	z = (x-mu)/sig
	return 0.5*(1 + math.erf(z/math.sqrt(2)))

print(round(cdf(x, muSum, sigSum), 4))