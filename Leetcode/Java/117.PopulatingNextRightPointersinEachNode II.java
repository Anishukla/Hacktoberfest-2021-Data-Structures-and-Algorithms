/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        
        Node head = root, curr = null, prev = null;
        
        while (head != null) {
            
            curr = head;
            
            //Reseting head and prev
            head = null;
            prev = null;
            
            while (curr != null) {
                
                Node firstChildOfcurr = null;
                
                if (curr.left != null) firstChildOfcurr = curr.left;
                else if (curr.right != null) firstChildOfcurr = curr.right;
                
                if (prev != null && firstChildOfcurr != null) prev.next = firstChildOfcurr; 
                
                // If head of the next row is not set
                if (head == null) head = firstChildOfcurr;
                
                if (curr.left != null && curr.right != null) {
                    curr.left.next = curr.right;
                    prev = curr.right;
                } else if (firstChildOfcurr != null) {
                    prev = firstChildOfcurr;
                } 
                
                curr = curr.next;
            }
            
        }
        
        return root;
    }
}

/* Time coplexity : O(n) where n = number of nodes in the tree 
   Space complexity : O(1)  
*/

/* Contributed by : Manish Das */