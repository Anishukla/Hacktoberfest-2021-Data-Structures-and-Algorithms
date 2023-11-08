# Enter your code here. Read input from STDIN. Print output to STDOUT

import math

N = int(input())
X = list(map(float, input().strip().split()))
Y = list(map(float, input().strip().split()))

mu_X = sum(X)/N
mu_Y = sum(Y)/N

stdX = (sum([(i - mu_X) ** 2 for i in X])/N) ** 0.5
stdY = (sum([(i - mu_Y) ** 2 for i in Y])/N) ** 0.5

covar = sum([(X[i] - mu_X) * (Y[i] - mu_Y) for i in range(N)])
corr_coff = covar / (N * stdX * stdY)

print(round(corr_coff, 3))