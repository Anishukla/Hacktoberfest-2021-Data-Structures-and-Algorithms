# Python3 program to find the   
# max LRproduct[i] among all i 
  
# Method to find the next greater 
# value in left side 
def nextGreaterInLeft(a): 
      
    left_index = [0] * len(a) 
    s = [] 
      
    for i in range(len(a)): 
          
        # Checking if current  
        # element is greater than top 
        while len(s) != 0 and a[i] >= a[s[-1]]: 
              
            # Pop the element till we can't 
            # get the larger value then 
            # the current value 
            s.pop() 
              
        if len(s) != 0: 
            left_index[i] = s[-1] 
        else: 
            left_index[i] = 0
  
        # Else push the element in the stack 
        s.append(i) 
  
    return left_index 
          
# Method to find the next  
# greater value in right 
def nextGreaterInRight(a): 
      
    right_index = [0] * len(a) 
    s = [] 
      
    for i in range(len(a) - 1, -1, -1): 
          
        # Checking if current element 
        # is greater than top 
        while len(s) != 0 and a[i] >= a[s[-1]]: 
              
            # Pop the element till we can't  
            # get the larger value then  
            # the current value 
            s.pop() 
              
        if len(s) != 0: 
            right_index[i] = s[-1] 
        else: 
            right_index[i] = 0
              
        # Else push the element in the stack 
        s.append(i) 
  
    return right_index 
          
def LRProduct(arr):  
      
    # For each element storing 
    # the index of just greater  
    # element in left side 
    left = nextGreaterInLeft(arr) 
  
    # For each element storing  
    # the index of just greater  
    # element in right side 
    right = nextGreaterInRight(arr) 
  
    ans = -1
  
    # As we know the answer will 
    # belong to the range from  
    # 1st index to second last index. 
    # Because for 1st index left 
    # will be 0 and for last  
    # index right will be 0 
    for i in range(1, len(left) - 1): 
          
        if left[i] == 0 or right[i] == 0: 
              
            # Finding the max index product 
            ans = max(ans, 0) 
        else: 
            temp = (left[i] + 1) * (right[i] + 1) 
              
            # Finding the max index product 
            ans = max(ans, temp) 
  
    return ans 
  
# Driver Code 
arr = [ 5, 4, 3, 4, 5 ] 
  
print(LRProduct(arr)) 