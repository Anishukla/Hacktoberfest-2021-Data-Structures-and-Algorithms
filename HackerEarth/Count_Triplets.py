# -*- coding: utf-8 -*-

arr = [1, 5, 5, 25, 125]
r=5
n=len(arr)
triplets=0
for i in range(0,n-1):
    print(i)
    if(arr[i+1]/arr[i]==r):
        triplets+=1

print(triplets)