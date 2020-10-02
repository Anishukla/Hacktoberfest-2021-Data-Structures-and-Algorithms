'''wap to find wethwer string are anagram'''

def mysort(s):    #Function to sort string	
	d=sorted(s)     #sorting string alphabetically
	s=''.join(d)
	return s

s1=input("enter first string") #first string
n1=mysort(s1) 

s2=input("enter second string") #second string
n2=mysort(s2)

if n1==n2:                       #Checking if they are same after sorting
	print("anagram")
else:
	print("not an anangram")