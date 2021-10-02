//Submitted by Mukesh Mahajan
//Github:- https://github.com/mukeshmjn


//141. Linked List Cycle- https://leetcode.com/problems/linked-list-cycle/


/*
example :-
Input: head = [3,2,0,-4], pos = 1
Output: true

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        //if head is null it will return 0 
        if(head==NULL)
            return 0;

        ListNode* slow= head;
        ListNode* fast = head;

        //slow will move one step and fast will move two step
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                return 1;
        }
        return 0;
    }
};


/* Time complexity of reversing a singly-linked list is O (n) 
since you will touch every single node.

Space Complexity : O(1)
 */
