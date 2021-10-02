# Enter your code here. Read input from STDIN. Print output to STDOUT

def getRank(dataset, number):
	rank = dict((a, i+1) for i,a in enumerate(sorted(set(dataset))))
	return [rank[a] for a in dataset]

N = int(input())
X = list(map(float, input().strip().split()))
Y = list(map(float, input().strip().split()))

rX = getRank(X, N) 
rY = getRank(Y, N)

d = [((rX[i] - rY[i]) ** 2) for i in range(N)]
rXY = 1 - (6 * sum(d))/ (N* (N*N - 1))

print('%.3f' %rXY)