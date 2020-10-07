#include<stdio.h>
#include<stdlib.h>
struct node
{
	int id;
	struct node *next;
};
struct node *start,*ptr,*new_node;
int main()
{
	int n,k,i,count;
	printf("enter the no of players: ");
	scanf("%d",&n);
	printf("\n enter the value that will be eliminated: ");  
	scanf("%d",&k);           // every kth player will be eliminated
	start=(struct node *)malloc(sizeof(struct node *));
	start->id=1;
	ptr=start;
	for(i=2;i<=n;i++)
	{
		new_node=(struct node *)malloc(sizeof(struct node *));
		ptr->next=new_node;
		new_node->id=i;
		new_node->next=start;
		ptr=new_node;
	}
	for(count=n;count>1;count--)
	{
		for(i=0;i<k-1;++i)
		{
			ptr=ptr->next;
			ptr->next=ptr->next->next;
		}
	}
	printf("\n the winner is %d player",ptr->id);
}
