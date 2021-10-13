#include<stdio.h>
#include<conio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;
void insert();
int delete();
int peek();
void display();

void main() {
    int ch, val;
    clrscr();
    while (1) {
        printf("MENU : ");
        printf(" 1. Insert\t2. Delete\t3. Peek\t\t4. Display\t5. EXIT");
        printf("\nEnter your option: ");
        scanf("%d", & option);
        switch (ch) {
        case 1:
            insert();
            break;
        case 2:
            val = delete();
            if (val != -1)
                printf("\nThe number deleted is: %d", val);
            printf("\n\n");
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("\nThe value at front of the queue is: %d", val);
            printf("\n\n");
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        }
    }
}

void insert() {
    int num;
    printf("\nEnter the number to be inserted in the queue: ");
    scanf("%d", & num);
    if (front == 0 && rear == MAXSIZE - 1)
        printf("\nQueue Full!!");
    else if ((rear+1) == front) {
      printf("\nQueue Full!!");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = num;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;
        queue[rear] = num;
    } else {
        rear++;
        queue[rear] = num;
    }
    printf("\n");
}

int delete() {
    int val;
    if (front == -1 && rear == -1) {
        printf("\nQueue Empty!!");
        return -1;
    }
    val = queue[front];
    if (front == rear)
        front = rear = -1;
    else {
        if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
    return val;
}

int peek() {
    if (front == -1 && rear == -1) {
        printf("\nQueue Empty!!");
        return -1;
    } else {
        return queue[front];
    }
}

void display() {
    int i;
    printf("\n");
    if (front == -1 && rear == -1)
        printf("\nQUEUE IS EMPTY");
    else {
        if (front < rear) {
            for (i = front; i <= rear; i++)
                printf("\t%d", queue[i]);
        } else {
            for (i = front; i < MAX; i++)
                printf("\t %d", queue[i]);
            for (i = 0; i <= rear; i++)
                printf("\t%d", queue[i]);
        }
    }
    printf("\n\n");
}
