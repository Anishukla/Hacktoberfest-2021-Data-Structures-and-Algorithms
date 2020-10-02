#To reverse a string with funtion


def rev_string(s):      #funtion to reverse string
	a=s[::-1]       
	return a

s1=input("enter the string ")  #taking input
r1=rev_string(s1)              #calling function

print(r1)                      #print the reverse of the string