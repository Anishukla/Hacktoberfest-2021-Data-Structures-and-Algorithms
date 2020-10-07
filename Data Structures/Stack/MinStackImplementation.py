class MinimumStack:
    # initialization the object with two empty stacks
    def __init__(self):
        self.stack=[]# for storing all the values
        self.ss=[] # contains current max

     # appending values to the stack 
     # append the value to the ss stack if new val is less than current min
    def append(self, val):
        self.stack.append(val)
        if self.ss==[] or val <=self.ss[-1]:
            self.ss.append(val)

     # implementing the peek method to get the top element of the stack
    def peek(self):
        return self.stack[-1]

     # returning the minimum value of the stack
    def min(self):
        return self.ss[-1]

       # removing the top element from the stack and if its the current min then pop that element from ss stack also 
    def pop(self):
        ans=self.stack.pop(-1)
        if ans==self.ss[-1]:
            self.ss.pop()
        return ans

