//LOGIC:
// First, we count the nodes using helper function countNodes.
// Now, we know that each part_size will be n / k, and the first left parts will have part_size + 1.
// In each iteration, we set res[i] to be our current node, and then move head as far as we need for this part - part_size + (i < left).
// We keep the prev to be able to split the parts.

class Solution {
public:
    int countNodes(ListNode* head) {
        int n = 0;
        while (head) {
            n++;
            head = head->next;
        }
        return n;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = countNodes(head);
        int part_size = n / k, left = n % k;
        ListNode *ptr = head, *prev = NULL;
        
        vector<ListNode*> res(k);
        for (int i = 0; i < k; i++) {
            res[i] = head;
            
            for (int j = 0; j < part_size + (i < left); j++) {
                prev = head; 
                head = head->next; 
            }
            if (prev) prev->next = NULL;
        }
        
        return res;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)