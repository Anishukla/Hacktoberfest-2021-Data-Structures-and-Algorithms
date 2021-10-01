class Node:
    def __init__(self,data):
        self.data = data
        self.next = None 
class Solution: 
    def insert(self,head,data):
            p = Node(data)           
            if head==None:
                head=p
            elif head.next==None:
                head.next=p
            else:
                start=head
                while(start.next!=None):
                    start=start.next
                start.next=p
            return head  
    def display(self,head):
        current = head
        while current:
            print(current.data,end=' ')
            current = current.next

    def removeDuplicates(self,head):
        p = head
        p0 = None
        while p:
            if p.next:
                if p0:
                    if p.next.data != p0.data:
                        p0.next = p.next
                        p0 = None
                else:
                    if p.next.data == p.data:
                        p0 = p
            else:
                if p0:
                    p0.next = None
                    p0 = None
            p = p.next
        return head
        #Write your code here

mylist= Solution()