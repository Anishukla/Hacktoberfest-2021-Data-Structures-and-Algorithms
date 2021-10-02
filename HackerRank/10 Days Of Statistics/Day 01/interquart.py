# Enter your code here. Read input from STDIN. Print output to STDOUT

import statistics as st 

n= int(input())
data = list(map(int, input().strip().split()))[:n]
freq = list(map(int, input().strip().split()))[:n]

s = []
for i in range(n):
	s += [data[i]] * freq[i]
N = sum(freq)
s.sort()

if n%2 != 0:
	q1 = st.median(s[:N//2])
	q3 = st.median(s[N//2+1:])
else:
	q1 = st.median(s[:N//2])
	q3 = st.median(s[N//2:])

print(round(float(q3-q1),1))