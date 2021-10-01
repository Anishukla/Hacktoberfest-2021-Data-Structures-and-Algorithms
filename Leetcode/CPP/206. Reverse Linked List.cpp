// Submitted by Sanjoy Saha
// Github - https://github.com/SanjoySaha24

/* 206.Reverse Linked List - https://leetcode.com/problems/reverse-linked-list/ 
example - 
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
            ListNode *curr=head;
    ListNode *prev=NULL;
    while(curr!=NULL){
        ListNode *next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
        
    }
};

/* Time complexity of reversing a singly-linked list is O (n) 
since you must touch every single node. */
