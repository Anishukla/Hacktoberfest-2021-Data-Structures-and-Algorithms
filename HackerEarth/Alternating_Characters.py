# -*- coding: utf-8 -*-

s="ABAB"
st="ABABAA"

d=0
n=len(st)
for char in range(0,n-1):
#    print(char,char+1)
    if(st[char] == st[char+1]):
       #print(st[char],st[char+1])
       d=d+1
        
print(d)