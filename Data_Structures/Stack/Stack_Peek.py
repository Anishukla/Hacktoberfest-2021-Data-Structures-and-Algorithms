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

# Function to return the top from stack without removing it 
def peek(stack): 
    if (isEmpty(stack)): 
        return str(-maxsize -1) # return minus infinite 
    return stack[len(stack) - 1] 

stack = createStack()
