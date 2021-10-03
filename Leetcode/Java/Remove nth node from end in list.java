//Github username : chaitanya-24
//Name: Chaitanya Sawant

//Problem Name : 19. Remove Nth Node From End of List

//Example:
//Input: head = [1,2,3,4,5], n = 2
//Output: [1,2,3,5]

//Input: head = [1], n = 1
//Output: []

//Time Complexity: O(n)
//Space Complexity:  O(1)


class Remove nth node from end in linkedlist {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode start = new ListNode(0);
        start.next = head;
        ListNode fast = start;
        ListNode slow = start;

        for(int i=1; i<=n+1; i++){
            fast = fast.next;
        }

        while(fast != null){
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;
        return start.next;
    }
}