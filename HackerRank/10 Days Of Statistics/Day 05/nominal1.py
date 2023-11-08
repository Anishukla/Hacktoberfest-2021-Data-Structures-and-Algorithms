# Enter your code here. Read input from STDIN. Print output to STDOUT

import math
mean, std = map(int, input().split())
lesstime = float(input())
timeA, timeB = map(int, input().split())

cdf = lambda x: 0.5 * (1+math.erf((x-mean) / (std * (2 ** 0.5))))

#     Less than 19.5
print('{:.3f}'.format(cdf(lesstime)))

#    Between 20 and 22
print('{:.3f}'.format(abs(cdf(timeB) - cdf(timeA))))
