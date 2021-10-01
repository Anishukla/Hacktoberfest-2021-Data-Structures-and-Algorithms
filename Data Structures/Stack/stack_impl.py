class Stack(object):
    
    def __init__(self):
        self.items = []
    
    def isEmpty(self):
        return self.items == []
    # checks if the stack is empty
    
    def push(self, items):
        self.items.append(items)
    # adds/pushes items into the stack
    
    def pop(self):
        return self.items.pop()
    # pops/removes items from the stack
    
    def peek(self):
        return self.items[len(self.items)-1]
    # returns the top element in the stack
    
    def size(self):
        return len(self.items)
    # returns the size of the stack (no. of elements in the stack)
    
    def display(self):
        print(self.items)
    # print the entire stack

st = Stack()
print("Is the stack empty?", st.isEmpty())
print("Elements pushed into the stack are:")
st.push(4)
st.push("Hey")
st.push(6)
st.push(False)
st.push(90)
st.push("This is a stack element")
st.push(87)
st.push("LAST")
st.display()
print("Peek element is {}." .format(st.peek()))
print("Is the stack empty?", st.isEmpty())
print("Popped element is {}." .format(st.pop()))
print("Final stack elements are:")
st.display()
print("Size of the queue is:", st.size())

# push(), pop(), isEmpty() and peek() take O(1) time

# Code contributed by Srinija Dharani (GitHub - @srinijadharani)