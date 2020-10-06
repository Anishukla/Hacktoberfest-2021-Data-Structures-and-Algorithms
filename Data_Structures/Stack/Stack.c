//Reo Correia - https://github.com/ReoCorreia
//Implimentation of stack using linked list
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node * next;
}
node;
node * top = NULL;
void push();
void pop();
void peep();
void display();

void main() {
    int option;
    clrscr();
    do {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Push");
        printf("\n 2: Pop");
        printf("\n 3: Peep");
        printf("\n 4: Display");
        printf("\n 5: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", & option);
        switch (option) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            printf("\nInvalid Option");

        }
    } while (option != 5);
    getch();
}

//To add value on top of the stack
void push() {
    node * new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", & num);
    new_node = (node * ) malloc(sizeof(node));
    new_node -> data = num;
    new_node -> next = top;
    top = new_node;

}

//To remove value from top of the stack
void pop() {
    node * ptr;
    if (top == NULL)
        printf("\n Stack empty!!can't delete");
    else {
        ptr = top;
        top = top -> next;
        printf("\n Value poped %d", ptr -> data);
        free(ptr);
    }
}

//To display the top most value in the stack
void peep() {
    if (top == NULL)
        printf("\n Stack empty!!");
    else
        printf("\n Value on top is %d", top -> data);
}

//To display all the value in the stack
void display() {
    node * ptr;
    ptr = top;
    if (ptr == NULL) {
        printf("\n Stack empty!!");
    } else {
        while (ptr != NULL) {
            printf("\t %d", ptr -> data);
            ptr = ptr -> next;
        }
    }
}
