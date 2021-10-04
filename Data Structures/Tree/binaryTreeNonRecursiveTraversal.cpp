// Nikhil Gupta
// Github:- Gupta-Nikhil85

// Program for printing binary tree in inorder, preorder and postorder fashion.

#include<bits/stdc++.h>
using namespace std;


class Node{
//Making a  Node class
public:
	// Making all the data members publically available to avoid getters and setters
    int data;
    Node* left;
    Node* right;

    Node (int d){
        data=d;
        left=right=NULL;
    }

};

//Preorder Build of the Tree Root, Left Tree, Right Tree.

Node * buildTree(){
    int d;
    cin>>d;

    //d==-1 represents a NULL node.

    if(d==-1){
        return NULL;
    }
    Node* n= new Node(d);
    n->left= buildTree();
    n->right=buildTree();
    return n;
}


void preorder(Node *root)
{
	stack<Node *> stk;
	while(!stk.empty() || root!=NULL){
		if(root!=NULL){

			//printing root data
			cout<<root->data<<" ";

			//pushing root in stack
			
			stk.push(root);

			// iterating for root->left.

			root=root->left;
		}
		else{
			// if root== NULL, then iterating on right side of top root node in stack.
			root=stk.top();
			stk.pop();
			root=root->right;
		}
	}
}

void inorder(Node *root)
{
	stack<Node *> stk;
	while(!stk.empty() || root!=NULL){
		if(root){
			//pushing root in stack
			stk.push(root);
			// iterating for root->left.
			root=root->left;
		}
		else{
			root=stk.top();
			stk.pop();
			//printing root data
			cout<<root->data<<" ";
			//iterating on right side of top root node in stack.
			root=root->right;
		}
	}
}
void postorder(Node *root){
	//creating two stacks, one for storing nodes
	// other for storing int values
	stack<Node *> stk1;
	stack<int> stk2;
	stk1.push(root);
	while(!stk1.empty()){
		//
		root=stk1.top();
		stk1.pop();
		stk2.push(root->data);
		
		if(root->left)
			stk1.push(root->left);
			//pushing root->left in stack 1.
		if(root->right)
			stk1.push(root->right);
			//pushing root->right in stack 1.
	}

	while(!stk2.empty()){
		//printing values
		cout<<stk2.top()<<" ";
		stk2.pop();
	}
}

int main(){
	cout<<"Enter elements of tree:-"<<endl;
	Node* root= buildTree();
	cout<<" pre order: ";
	preorder(root);
	cout<<endl;
	cout<<" in order: ";
	inorder(root);
	cout<<endl;
	cout<<" post order: ";
	postorder(root);
	cout<<endl;
	return 0;
}
