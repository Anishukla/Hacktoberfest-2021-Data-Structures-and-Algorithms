# Enter your code here. Read input from STDIN. Print output to STDOUT

import math

n = float(input())
mean = float(input())
std = float(input())
percent_ci = float(input())
value_ci = float(input())

ci = value_ci * (std/math.sqrt(n))

print(round(mean-ci,2))
print(round(mean+ci,2))