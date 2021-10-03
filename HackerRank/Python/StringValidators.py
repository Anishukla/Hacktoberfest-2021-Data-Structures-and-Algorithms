# Time Complexity --> O(n) ; where n is the length of input string
# Code by Gopi Vaibhav --> https://github.com/gopivaibhav

s=input()
num,low,up,other=0,0,0,0
for i in range(len(s)):
    if(ord(s[i])>=48 and ord(s[i])<=57):
        num+=1
    if(ord(s[i])>=97 and ord(s[i])<=122):
        low+=1
    if(ord(s[i])>=65 and ord(s[i])<=90):
        up+=1
    else:
        other+=1
if(num>0 or low>0 or up>0):
    print("True")
else:
    print("False")
if(low>0 or up>0):
    print("True")
else:
    print("False")
if(num>0):
    print("True")
else:
    print("False")
if(low>0):
    print("True")
else:
    print("False")
if(up>0):
    print("True")
else:
    print("False")

# Sample input --> qA2

# Output :-
# True
# True
# True
# True
# True