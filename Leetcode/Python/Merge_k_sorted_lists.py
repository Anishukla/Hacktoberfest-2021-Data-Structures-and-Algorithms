"""
Problem Description:
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
"""
# Brute-force Algorithm
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        arr = []
        for llist in lists:
            temp = llist
            # for every linked list in 'lists', add every value in an array 'arr'
            while temp is not None:
                arr.append(temp.val)
                temp = temp.next
        # Trivial Case handling (return None if 'lists' is empty)
        if len(arr) == 0:
            return None
        # Applying usort to sort the array
        arr.sort()
        llist = ListNode(arr[0])
        temp = llist
        # Converting the list into a linked list.
        for i in range(1, len(arr)):
            node = ListNode(arr[i])
            temp.next = node
            temp = temp.next
        return llist