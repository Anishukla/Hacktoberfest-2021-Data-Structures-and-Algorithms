#!/usr/bin/env python
# coding: utf-8

# In[1]:


#To check if given number is armstrong number or not
#Get the number as an positive integer
no=int(input())

#converting the number into a string
no_as_str=str(no)

#count the number of elements in the string i.e the number of digits in the integer
n=len(no_as_str)

sum_no=0  #Initialize sum_no as 0

for i in range(n):
    sum_no=sum_no+pow(int(no_as_str[i]),n)  #taking each digit, and converting it into integer. Using pow() function to calculate the nth time multipication of the digit and  add it to the sum_no

#compare the calculated sum to the given integer   
if sum_no==no:
    print('The given number %d is an armstrong number' %no)  #if the calculated sum is equal to the given integer
else:
    print('The given number %d is not an armstrong number' %no) #if the calculated sum is not equal to the given integer


# In[ ]:




