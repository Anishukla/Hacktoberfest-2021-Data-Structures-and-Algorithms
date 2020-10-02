#include <bits/stdc++.h> 
using namespace std; 
  
void Print(queue<int>& Queue) 
{ 
    while (!Queue.empty()) { 
        cout << Queue.front() << " "; 
        Queue.pop(); 
    } 
} 
  
// Function to reverse the queue 
void reverseQueue(queue<int>& Queue) 
{ 
    stack<int> Stack; 
    while (!Queue.empty()) { 
        Stack.push(Queue.front()); 
        Queue.pop(); 
    } 
    while (!Stack.empty()) { 
        Queue.push(Stack.top()); 
        Stack.pop(); 
    } 
} 
  
// Driver code 
int main() 
{ 
    queue<int> q; 
    q.push(10); 
    q.push(20); 
    q.push(30); 
    q.push(40); 
    q.push(50); 
    q.push(60); 
    q.push(70); 
    q.push(80); 
    q.push(90); 
    q.push(100); 
  
    reverseQueue(q); 
    Print(q); 
} 
