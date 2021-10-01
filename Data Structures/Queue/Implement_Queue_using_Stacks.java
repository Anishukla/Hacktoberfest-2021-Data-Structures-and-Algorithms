// Implement Queue using Stacks

class MyQueue {
    private int front;
    Stack<Integer> s1 = new Stack<>();
    Stack<Integer> s2 = new Stack<>();
    
    /** Initialize your data structure here. */
    public MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    public void push(int x) {
         if (s1.empty())
        front = x;
    while (!s1.isEmpty())
        s2.push(s1.pop());
    s2.push(x);
    while (!s2.isEmpty())
        s1.push(s2.pop());
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        int x= s1.pop();
    if (!s1.empty())
    { front = s1.peek();}
        return x;
    } 
    /** Get the front element. */
    public int peek() {
        return front;
    }
    
    /** Returns whether the queue is empty. */
    public boolean empty() {
        return s1.isEmpty();
        
    }
}
