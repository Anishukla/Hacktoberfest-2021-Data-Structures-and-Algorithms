# Enter your code here. Read input from STDIN. Print output to STDOUT
import numpy as np 
from scipy import stats

n = int(input())
elements = list(map(int,input().split()))
print(np.mean(elements))
print(np.median(elements))
print(int(stats.mode(elements)[0]))