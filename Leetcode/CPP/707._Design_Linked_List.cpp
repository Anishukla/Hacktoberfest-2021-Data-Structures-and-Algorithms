//Question Link -: https://leetcode.com/problems/design-linked-list/

//Solution -:

class Node {
public:
	int val;
	Node *next;
	Node(int value) {
		val = value;
		next = NULL;
	}
};
class MyLinkedList {
public:
	/** Initialize your data structure here. */
	Node* head = new Node(0);
	Node* temp = head;
	MyLinkedList() {

	}

	/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
	int get(int index) {
		// temp = head;
		// while (temp != NULL) {
		//     cout << temp->val << " ";
		//     temp = temp->next;
		// }
		// cout << endl;
		temp = head;
		index++;
		while (temp != NULL and index >= 0) {
			if (index == 0) {
				return temp->val;
			}
			index--;
			temp = temp->next;
		}
		return -1;
	}

	/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
	void addAtHead(int val) {
		// temp = head;
		// while (temp != NULL) {
		//     cout << temp->val << " ";
		//     temp = temp->next;
		// }
		// cout << endl;
		temp = head;
		Node* new_node = new Node(val);
		temp = temp->next;
		head->next = new_node;
		new_node->next = temp;
	}

	/** Append a node of value val to the last element of the linked list. */
	void addAtTail(int val) {
		// temp = head;
		// while (temp != NULL) {
		//     cout << temp->val << " ";
		//     temp = temp->next;
		// }
		// cout << endl;
		temp = head;
		Node* new_node = head;
		while (new_node->next != NULL) {
			new_node = new_node->next;
		}
		new_node->next = new Node(val);
	}

	/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
	void addAtIndex(int index, int val) {
		// temp = head;
		// while (temp != NULL) {
		//     cout << temp->val << " ";
		//     temp = temp->next;
		// }
		// cout << endl;
		temp = head;
		//index--;
		while (temp != NULL and index >= 0) {
			if (index == 0) {
				Node* curr = temp->next;
				temp->next = new Node(val);
				temp = temp->next;
				temp->next = curr;
				break;
			}
			index--;
			temp = temp->next;
		}
	}

	/** Delete the index-th node in the linked list, if the index is valid. */
	void deleteAtIndex(int index) {
		// temp = head;
		// while (temp != NULL) {
		//     cout << temp->val << " ";
		//     temp = temp->next;
		// }
		// cout << endl;
		temp = head;
		//index--;
		while (temp != NULL and index >= 0) {
			if (index == 0) {
				if (temp->next != NULL) {
					Node* curr = temp->next->next;
					temp->next = curr;
				}
				break;
			}
			index--;
			temp = temp->next;
		}
	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */