"""
@author: anishukla
"""

"""Implementing a function recursively to get the desired
Fibonacci sequence value."""

def fibonacci(position):
    if position == 0:
        return 0
    elif position == 1 or position ==2 :
        return 1
    elif position > 2:
        return fibonacci(position-1)+fibonacci(position-2)
    return -1


print("Enter number of test cases you want: ")        
T = int(input())
for i in range(T):
    print("Input the position for fibonacci value: ")
    N = int(input())
    print("Fibonacci(%d) = " %N , fibonacci(N))
    
#Complexity is O(n!)
