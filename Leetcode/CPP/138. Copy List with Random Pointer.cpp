// LOGIC:
// Consider l1 as a node on the 1st list and l2 as the corresponding node on 2nd list.
// Step 1:
// Build the 2nd list by creating a new node for each node in 1st list. 
// While doing so, set the next pointer of the new node to the random pointer 
// of the corresponding node in the 1st list.  And set the random pointer of the 
// 1st list's node to the newly created node.
// Step 2:
// The new head is the node pointed to by the random pointer of the 1st list.
// Step 3:
// Fix the random pointers in the 2nd list: (Remember that l1->random is l2)
// l2->random will be the node in 2nd list that corresponds to the node in the 
// 1st list that is pointed to by l2->next, 
// Step 4:
// Restore the random pointers of the 1st list and fix the next pointers of the 
// 2nd list. random pointer of the node in 1st list is the next pointer of the 
// corresponding node in the 2nd list.  This is what we had done in the 
// 1st step and now we are reverting back. next pointer of the node in 
// 2nd list is the random pointer of the node in 1st list that is pointed to 
// by the next pointer of the corresponding node in the 1st list.
// Return the new head that we saved in step 2.

RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *newHead, *l1, *l2;
    if (head == NULL) return NULL;

    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = new RandomListNode(l1->label);
        l2->next = l1->random;
        l1->random = l2;
    }
    
    newHead = head->random;
    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = l1->random;
        l2->random = l2->next ? l2->next->random : NULL;
    }
    
    for (l1 = head; l1 != NULL; l1 = l1->next) {
        l2 = l1->random;
        l1->random = l2->next;
        l2->next = l1->next ? l1->next->random : NULL;
    }

    return newHead;
}
//Time Complexity:O(n)
//Space Complexity:O(n)