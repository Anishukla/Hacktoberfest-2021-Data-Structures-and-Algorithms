# Enter your code here. Read input from STDIN. Print output to STDOUT

from math import sqrt
n= int(input())
x = sorted(list(map(int, input().strip().split()))[:n])
u = sum(x)/n
print( sqrt(sum([(x[i]-u)**2 for i in range (n)])/n) )
