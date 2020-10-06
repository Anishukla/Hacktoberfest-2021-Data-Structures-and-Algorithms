#include<iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
};
void deleteLast();
Node *dll = new Node();
unsigned int sz = 0;
void createNode(int a)
{
    dll->val = a;
    dll->next = NULL;
    dll->prev = NULL;
    sz++;
}
void insertStart(int a)
{
    Node* newNode = new Node();
    newNode->val = a;
    newNode->next = dll;
    newNode->prev = NULL;
    dll->prev = newNode;
    dll = newNode;
    sz++;
}
void insertPos(int a, int pos)
{
    Node* newNode = new Node();
    Node* temp = new Node();
    newNode->val = a;
    temp = dll;
    pos = pos-1;
    for(int i=0;i<pos-1;i++)
        temp = temp->next;
    newNode->next = temp->next;
    newNode->prev = temp;
    (newNode->next)->prev = newNode;
    temp->next = newNode;
    sz++;
}
void insertLast(int a)
{
    Node* newNode = new Node();
    Node* temp = new Node();
    newNode->val = a;
    temp = dll;
    while(temp->next != NULL)
    {
        temp= temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    newNode->prev = temp;
    sz++;
}
void deleteStart()
{
    if(sz==0)
        cout<<"Can not delete as list is empty"<<endl;
    else if(sz==1)
    {
        dll = NULL;
        sz--;
    }
    else
    {
        Node* temp = new Node();
        temp = dll;
        dll = dll->next;
        dll->prev = NULL;
        delete temp;
        sz--;
    }
}
void deletePos(int pos)
{
    if(pos == 1)
        deleteStart();
    else if(pos == sz)
        deleteLast();
    else
    {
        if(sz==0)
            cout<<"Can not delete as list is empty"<<endl;
        else if(sz==1)
        {
            dll = NULL;
            sz--;
        }
        else
        {
            Node* temp = new Node();
            Node* temp1 = new Node();
            temp = temp1 = dll;
            for(int i=0;i<pos-2;i++)
            {
                temp= temp->next;
            }
            temp1 = temp->next;
            temp->next = temp1->next;
            (temp1->next)->prev = temp;
            delete temp1;
            sz--;
        }
    }
}
void deleteLast()
{
    if(sz==0)
        cout<<"Can not delete as list is empty"<<endl;
    else if(sz==1)
    {
        dll = NULL;
        sz--;
    }
    else
    {
        Node* temp = new Node();
        Node* temp1 = new Node();
        temp = dll;
        for(int i=0;i<sz-2;i++)
        {
            temp= temp->next;
        }
        temp1 = temp->next;
        temp->next = NULL;
        delete temp1;
        sz--;
    }
}
void searchVal(int val)
{
    if(sz==0)
        cout<<"List is empty"<<endl;
    else
    {
        int i;
        Node* temp = new Node();
        temp = dll;
        for(i=0;i<sz;i++)
        {
            if(temp->val == val)
            {
                cout<<"ELEMENT IS THERE IN POSITION "<<i+1<<endl;
                break;
            }
            temp = temp->next;
        }
        if(i==sz)
            cout<<"ELEMENT NOT THERE IN THE LIST."<<endl;
    }
}
void printList()
{
    if(sz==0)
        cout<<"List is empty"<<endl;
    else
    {
        Node* temp = new Node();
        temp = dll;
        while(temp->next != NULL)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<temp->val<<endl;
    }
}
int main()
{
    int val, pos, ch;
    cout<<"Enter value for first node:"<<endl;
    cin>>val;
    createNode(val);
    do
    {
        cout<<"Enter: \n 1 - Insert node at start \n 2 - Insert node at a particular position \n 3 - Insert node at last \n";
        cout<<" 4 - Delete the first node \n 5 - Delete the node at a particular position \n 6 - Delete the last node \n";
        cout<<" 7 - Search an element \n 8 - Print the list \n 9 - To exit \n";
        cout<<"Enter YOUR CHOICE:";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"Enter a value:";
            cin>>val;
            insertStart(val);
            break;
        case 2:
            cout<<"Enter a value and position to insert the node:";
            cin>>val>>pos;
            insertPos(val, pos);
            break;
        case 3:
            cout<<"Enter a value:";
            cin>>val;
            insertLast(val);
            break;
        case 4:
            deleteStart();
            break;
        case 5:
            cout<<"Enter the position of node to be deleted:";
            cin>>pos;
            deletePos(pos);
            break;
        case 6:
            deleteLast();
            break;
        case 7:
            cout<<"Enter the value to be searched:";
            cin>>val;
            searchVal(val);
            break;
        case 8:
            printList();
            break;
        case 9:
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }while(ch != 9);
    return 0;
}
