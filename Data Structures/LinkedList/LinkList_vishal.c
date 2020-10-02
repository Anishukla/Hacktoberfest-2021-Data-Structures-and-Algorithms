#include<stdio.h>
#include<conio.h>
/*this will create a structure with a data element known as "info" and a next pointer called "next" */
typedef struct node
{
	int info;
	struct node *next;
} node;

/*this will assign space to a link list node using malloc and take input from user for node value*/
node* create()
{
	node *head=NULL,*temp,*last;
	int val;
	do
	{
	printf("Enter the info vale ");
	scanf("%d",&val);
	temp=(node*)malloc(sizeof(node));
	temp->info=val;
	temp->next=NULL;
	if(head==NULL)
	{
		last=head=temp;
	}
	else	
	{
		last->next=temp;
		last=temp;
	}
	}while(val!=-1);	
return head;
}

/* used for traversing the full link list*/
node* traverse(node *head)
{
node *pr;
pr=head;
while(pr->next!=NULL)
	{printf("-> %d",pr->info);
	 pr=pr->next;
	}
}

/* main function with usual options for a link list */
void main()
{
	int choise;
	prinf("\t Enter your choise");
	printf("1 create Node \n");
	printf("2 traverse Node \n");
	printf("3 Maximum Value in a Node \n");	
	printf("4 exit");
	switch(choise)
		{
			case 1: create();
		}
}
	