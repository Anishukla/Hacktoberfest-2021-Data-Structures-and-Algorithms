# Enter your code here. Read input from STDIN. Print output to STDOUT

def geo_dist(n, p):
	return ((1-p)**(n-1))*p

a, b = list(map(int, input().split()))
n = int(input())
print('{:.3f}'.format(geo_dist(n, a/b)))