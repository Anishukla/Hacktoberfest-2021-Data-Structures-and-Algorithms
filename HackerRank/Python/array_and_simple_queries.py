"""
Author : Pavitra Pati
Github id = pavitrapati
Date :2nd October 2021
Description : Hackerrank 'Arrays and Queries' question from problem solving section. Difficulty level = Hard
Time complexity=O(M*sqrt(N)) {N and M are given in question. This time complexity baciscally means that each 
query will take sqrtN operations and it is required to run M times.}
Logic : It uses logic of BALANCED TREES data structure
"""
from array import array
n, n_queries = map(int, input().split())
data = array('L', map(int, input().split()))
assert len(data) == n
for m in range(n_queries):
    t, i, j = map(int, input().split())
    if t == 1:
        aux1 = i-1
        aux2 = j - aux1
        data[:aux2], data[aux2:j] = data[aux1:j], data[:aux1]
    else:
        aux1 = i-1
        aux2 = aux1 + n - j
        data[aux1:aux2], data[aux2:] = data[j:], data[aux1:j]
print(abs(data[0] - data[-1]))
print(*data)