import sys

class Solution:
    # Write your code here
    def __init__(self):
          self.mystack = list()
          self.myqueue = list()
          return(None)

    def pushCharacter(self, char):
          self.mystack.append(char)

    def popCharacter(self):
          return(self.mystack.pop(-1))

    def enqueueCharacter(self, char):
          self.myqueue.append(char)

    def dequeueCharacter(self):
          return(self.myqueue.pop(0))
# read the string s