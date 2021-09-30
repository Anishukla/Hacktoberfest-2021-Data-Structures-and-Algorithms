# -*- coding: utf-8 -*-

s1="aardvark"
s2="apple"

count=0
l1=len(s1)
l2=len(s2)
for i in range(0,l1-1):
    for j in range(0,l2):
        if(s1[i]==s2[j]):
            count+=1

if(count!=0):    
    print(count)
else:
    print("NO")