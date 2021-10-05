// Submitted by Sanjoy Saha
// Github - https://github.com/SanjoySaha24

/* 21. Merge Two Sorted Lists -https://leetcode.com/problems/merge-two-sorted-lists/

example - 
Input: l1 = [], l2 = [0]
Output: [0]

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if (l1->val > l2->val) std::swap(l1,l2);
        ListNode * res = l1;
        while ( l1!= NULL && l2 != NULL){
            ListNode * tmp = NULL;
            while (l1 != NULL && l1->val <= l2->val){
                tmp=l1;
                l1 = l1->next;
                
            }
            tmp->next = l2;
            std::swap(l1,l2);
            
        }
        return res;
        
    }
};

/* Time Complexity: Since we are traversing through the two
 lists fully. So, the time complexity is O(m+n) where m and n are
  the lengths of the two lists to be merged. */
