Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3

ANSWER--
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
         ListNode *temphead=new ListNode(0);
        temphead->next=head;
        ListNode * temp=head;
        ListNode * prev =temphead;
        while(temp!= NULL)
        {
            while(temp->next!= NULL && temp->val==temp->next->val)
                temp=temp->next;
            if(prev->next == temp)
                prev=prev->next;
            else
                prev->next=temp->next;
            temp=temp->next;
                
        }
        return temphead->next;
    }
};
