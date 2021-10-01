# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
def createNewNode(x: ListNode)-> ListNode:
    x.next = ListNode()
    return x.next
    
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1 = 0
        count1 = 1
        num2 = 0
        count2 = 1
        x = l1
        y = l2
        while x.next is not None:
            num1 += count1 * x.val
            count1 *= 10
            x = x.next
        num1 += count1 * x.val
        
        while y.next is not None:
            num1 += count2 * y.val
            count2 *= 10
            y = y.next
        num2 += count2 * y.val
        
        reqNo = num1 + num2
        something = []
        while reqNo != 0: 
            x = ListNode()
            x.val = reqNo % 10
            reqNo //= 10
            something.append(x)
        for x in range(len(something)):
            if(x +1 < len(something)):
                something[x].next = something[x+1]
        if len(something) == 0:
            return ListNode(val= 0)
        else:
            return something[0]
            
            
            
        
        