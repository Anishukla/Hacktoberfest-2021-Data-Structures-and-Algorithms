'''Reverse the words in a string
eg: I am tired---> I ma derit'''
def rev_string(s):      #function to reverse word
	a=s[::-1]
	return a

s1 = input("enter a sentence ")
d1 = s1.split(' ')
ns1 = ""

for d in d1:     #Running a for loop for each word and concating it
	ns1 =ns1+' '+rev_string(d)

print("original ", s1, " modified ", ns1)