# Enter your code here. Read input from STDIN. Print output to STDOUT

import math

def cumul(mean, std, value):
	return 0.5 * (1+math.erf((value-mean)/(std * (2 ** 0.5))))

max_wt = float(input())
n = float(input())
mean = float(input())
std = float(input())

new_mean = mean * n
new_std = math.sqrt(n) * std

print(round(cumul(new_mean, new_std, max_wt),4))