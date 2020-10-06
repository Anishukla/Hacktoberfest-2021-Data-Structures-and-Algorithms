# Python program for implementation of stack 
  
# import maxsize from sys module  
# Used to return -infinite when stack is empty 
from sys import maxsize 
  
# Function to create a stack. It initializes size of stack as 0 
def createStack(): 
    stack = [] 
    return stack 
  
# Stack is empty when stack size is 0 
def isEmpty(stack): 
    return len(stack) == 0
  
# Function to add an item to stack. It increases size by 1 
def push(stack, item): 
    stack.append(item) 
    print(item + " pushed to stack ") 
# Object Creation      
stack = createStack() 



