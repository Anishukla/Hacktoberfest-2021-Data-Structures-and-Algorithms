#!/bin/python3

import sys

n = int(input().strip())
a = list(map(int, input().strip().split(' ')))
# Write Your Code Here


num_swaps = 0
# print(a)

for i in range(n):
    for j in range(n-1):
        if a[j+1] < a[j]:
            a[j+1],a[j] = a[j],a[j+1]
            num_swaps += 1

print("Array is sorted in",num_swaps,"swaps.\nFirst Element:",a[0],"\nLast Element:",a[n-1])
