#include <stdio.h>
#include <stdlib.h>

struct node{
	
	int data;
	struct node *next;
} *head= NULL;

void display(struct node *p){
	
	do{
		
		printf("%d\t", p->data);
		p= p->next;
	}while(p!= head);
}

void insert(struct node *p, int pos, int x){
	
	int i;
	
	struct node *t= (struct node*) malloc(sizeof(struct node));
	t->data= x;
	
	if(pos== 0){
		
		if(head== NULL){
			
			head= t;
			head->next= head;
		}
		
		else{
			
			while(p->next!= head)
				p= p->next;
				
			p->next= t;
			t->next= head;
			head= t;
		}
	}
	
	else{
		
		for(i= 0; i< pos-1; i++)
			p= p->next;
			
		t->next= p->next;
		p->next= t;
	}
}

int deleteCLL(struct node *p, int pos){
	
	int x, i;
	struct node *q;
	
	if(pos== 1){
		
		while(p->next!= head)
			p= p->next;
			
		x= head->data;
		
		if(p== head){
			free(head);
			head= NULL;
		}
		
		else{
			p->next= head->next;
			free(head);
			head= p->next;
		}
	}
	
	else{
		
		for(i= 0; i< pos-2; i++)
			p= p->next;
			
			q= p->next;
			
			p->next= q->next;
			x= q->data;
			free(q);
	}
	
	return x;
}

int main(){
	
	int pos, x, t= 5;
	
	while(t){
		
		scanf("%d %d",&pos, &x);
		insert(head, pos, x);      //to insert in linked list
		display(head);
		printf("\n\n");
		
		t--;
	}
	
	
	while(1){
		
		scanf("%d",&pos);
		x= deleteCLL(head, pos);       //This function will delete from Circular Linked list
		printf("%d is deleted\n", x);
		display(head);                       //This is to Display Circular Linked list
		printf("\n\n");
		
		t--;
	}
}
