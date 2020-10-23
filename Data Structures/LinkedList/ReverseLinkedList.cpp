class node{
	public:
		int data;
		node *next;
};
node* reverseList(node *head){
	node *pre=NULL;
	node *nxt=NULL;
	node *cur=head;
	while(cur!=NULL){
		nxt=cur->next;
		cur->next=pre;
		pre=cur;
		cur=nxt;
	}
	head=pre;
}
