# -*- coding: utf-8 -*-
"""
@author: anishukla
"""

def maxSubArray(A):
    val = []
    val.append(A[0])
    req = A[0]
    for i in range(1, len(A)):
        req = max(req+A[i], A[i])
        val.append(req)
        
    res = max(val)
    
    return res

A = list(map(int, input().split()))

print(maxSubArray(A))