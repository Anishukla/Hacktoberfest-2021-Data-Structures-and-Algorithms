# Enter your code here. Read input from STDIN. Print output to STDOUT
from statistics import median 

n= int(input())
x = sorted(list(map(int,input().strip().split()))[:n])
print(int(median(x[:n//2])))
print(int(median(x)))
print(int(median(x[(n+1)//2:])))
