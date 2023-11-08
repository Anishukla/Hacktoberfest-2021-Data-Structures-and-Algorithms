# Enter your code here. Read input from STDIN. Print output to STDOUT

import math
mean, std = map(int, input().split())
higher = int(input())
passed = int(input())

cdf = lambda x: 0.5*(1+math.erf((x-mean)/(std*(2 ** 0.5))))

#	grade> higher
print(round((1-cdf(higher))*100,2))
#	grade>=pass
print(round((1-cdf(passed))*100,2))
#	grade<pass
print(round((cdf(passed))*100,2))