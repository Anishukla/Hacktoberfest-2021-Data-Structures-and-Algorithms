# Enter your code here. Read input from STDIN. Print output to STDOUT

import numpy as np

m,n = map(int, input().split()) 
lists = [list(map(float, input().split())) for _ in range(n)]

X = np.empty((n, m+2))
X[:,0] = 1
X[:,1:] = lists
Y = X[:,-1]
X = X[:,:-1]

B = np.dot(np.linalg.inv(np.dot(X.T, X)), np.dot(X.T,Y))
q = int(input())
X = np.empty((q, m+1))
X[:,0] = 1

lists = [list(map(float, input().strip().split())) for _ in range(q)]
X[:,1:] = lists

print('\n'.join(map(str, np.round(np.dot(X,B),2))))