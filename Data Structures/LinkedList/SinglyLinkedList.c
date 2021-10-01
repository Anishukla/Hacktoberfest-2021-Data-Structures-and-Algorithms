#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<stddef.h>
struct node
{
    int data;
    struct node *next;

}*start=NULL;
main()
{

    int i,choice,n,d,pos,count;
    void create_list(int);
    void display();
    void insert_begin(int);
    void insert_specific(int,int);
    void del_node(int);
    void count_nodes();
    void search(int);
    void reverse();
while(1)
{

    printf("press 1 to create the list");
    printf("\npress 2 to display the list");
    printf("\npress 3 to insert a node at beginning");
    printf("\npress 4 to insert a node at specific position");
    printf("\npress 5 to delete a node at specific position");
    printf("\npress 6 to count the node");
    printf("\npress 7 to seach an element");
    printf("\npress 8 to reverse the linked list:");
    printf("\npress 9 to exit");
    printf("\nEnter the choice:");
    scanf("%d",&choice);
    switch(choice)
    {

        case 1:printf("\nEnter the initial size:");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("\nEnter the initial population:");
                    scanf("%d",&d);
                    create_list(d);

                }
                break;
        case 2:display();
                break;
        case 3:printf("\nEnter the value of the node:");
                scanf("%d",&d);
                insert_begin(d);
                break;
        case 4:printf("\nEnter the position &value of the node");
                scanf("%d %d",&pos,&d);
                insert_specific(pos,d);
                break;
        case 5:printf("\nEnter the position of node to delete:");
                scanf("%d",&d);
                del_node(d);
                break;
        case 6:count_nodes();
                break;
        case 7:printf("\nEnter the element to search:");
                scanf("%d",&d);
                search(d);
                break;
        case 8:reverse();
                break;
        case 9:exit(0);

    }
}
}
void create_list(int num)
{

    struct node *temp,*q;
    temp=malloc(sizeof(struct node));
    temp->data=num;
    if(start==NULL)
    {
        temp->next=start;
        start=temp;
    }
    else
    {
        q=start;
        while(q->next!=NULL)
            q=q->next;
            temp->next=q->next;
            q->next=temp;

    }

}
void display()
{
    struct node *q;
    q=start;
    while(q!=NULL)
    {
        printf("%d",q->data);
        q=q->next;
    }

}
void insert_begin(int d)
{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    temp->data=d;
    temp->next=start;
    start=temp;
}
void insert_specific(int p,int num)
{


    struct node *q,*temp;
    int count=0;
    temp=malloc(sizeof(struct node));
    temp->data=num;
    q=start;
    while(count<p-1)
    {
        q=q->next;
        if(q==NULL)
        {
            printf("incorrect position");
            exit(0);
        }
        count++;
    }
    temp->next=q->next;
}
void del_node(int pos)
{
    struct node *q,*temp;
    int count;
    q=start;
    count=0;
    while(count<pos-1)
    {
        q=q->next;
        count++;
    }
    temp=q->next;
    q->next=temp->next;
    free(temp);
}
void count_nodes()
{
    int count;
    struct node*q;
    q=start;
    count=0;
    while(q!=NULL)
    {
        count++;
        q=q->next;
    }
    printf("\nTotal number of elements in the list:%d",count);
}
void search(int num)
{
    struct node *q;
    int count,flag;
    q=start;
    count=0;
    flag=0;
    while(q!=NULL)
    {
        if(q->data==num)
        {

            flag=1;
            break;
        }
    count++;
    q=q->next;
}
if(flag==1)
    printf("Data found in index:%d",count+1);
else
    printf("Data is not found in index");
}
void reverse()
{
    struct node *q,*p1,*p2,*p3;
    p1=start;
    p2=p1->next;
    p3=p2->next;
    p1->next=NULL;
    p2->next=p1;
    while(p3!=NULL)
    {
        p1=p2;
        p2=p3;
        p3=p3->next;
        p2->next=p1;
    }
    start=p2;
}