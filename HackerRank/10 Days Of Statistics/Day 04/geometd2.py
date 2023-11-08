# Enter your code here. Read input from STDIN. Print output to STDOUT

p = list(map(int, input().split()))
l = int(input())

frac = p[0]/p[1]
q = 1-frac
n=1
k=0

for i in range(l):
	j = pow(q,n-1)
	m = j*frac
	k = k+m
	n = n+1

print(round(k,3))

