# -*- coding: utf-8 -*-

#QUESTION-> 
#You will be given an array of integers and a target value. 
#Determine the number of pairs of array elements that have a difference equal to a target value.
#
#For example, given an array of [1, 2, 3, 4] and a target value of 1, 
#we have three values meeting the condition:



arr = [1,5,3,4,2]
k=2
n=len(arr)
arr.sort()
#if(n==0):
#    return 0
#elif(n==1):
#    return arr[0]
#elif (n==2):
#    if(abs.arr[0]-abs.arr[1]==k):
#        return 1
pairs=0

for i in range(0,n-1):
    
    for j in range(1,n):
        print(i,j)
#        if( abs(arr[j])-abs(arr[i])==k):
#            pairs+=1

    
        
#print(pairs)