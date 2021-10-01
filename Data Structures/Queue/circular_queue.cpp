// Circular queue implementation using struct key 
#include <iostream>
using namespace std;

struct Queue
{
    int cap, size, front;
    int *arr;

    Queue(int x)
    {
        cap = x;
        size = front = 0;
        arr = new int[cap];
    }

    bool isFull() // Func to return true if queue is full
    {
        return (size == cap);
    }

    bool isEmpty() // Func to return true if queue is empty
    {
        return (size == 0);
    }

    void enqueue(int c) // Adding element in queue
    {
        if (isFull())
            return;
        arr[(front + size) % cap] = c;
        size++;
    }
    void dequeue() // Removing element from queue
    {
        if (isEmpty())
            return;
        front++;
        front = front % cap;
        size--;
    }
    int getRear() // Getting the index of last item
    {
        if (isEmpty())
            return -1;
        return (front + size - 1) % cap;
    }
    int getFront() // Getting the index of first item
    {
        if (isEmpty())
            return -1;
        return front;
    }
    void display() // Displaying the elements in the queue
    {
        if (isEmpty())
            return;
        for (int i = 0; i < size; i++)
        {
            cout << arr[(front + i) % cap] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int c;
    cout << "Enter the capacity of queue: ";
    cin >> c;
    Queue q(c); // Queue with name q and capacity c is created
    
}