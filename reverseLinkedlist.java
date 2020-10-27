class ReverseLL
{
    // This function should reverse linked list and return
    // head of the modified linked list.
    Node reverseList(Node head)
    {
        // code here
        if(head.next==null ||  head==null )
            return head;
        Node second =head.next;
        Node start = reverseList(head.next);
        second.next=head;
        head.next=null;
        
        return start;
    }
}
