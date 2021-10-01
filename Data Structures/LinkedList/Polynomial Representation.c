//To represent a polynomial using linked list

#include<stdio.h>
#include<stdlib.h>


struct node
{
    int coeff;
    int pow;
    struct node *next;
};
typedef struct node *poly;



void CreatePoly(poly link,int p)
{
    int i;
    printf("Enter coefficient for degree %d : ",p);
    scanf("%d",&link->coeff);
    link->pow=p;
    link->next=NULL;
    for(i=p-1;i>=0;i--)
    {
        link->next=(struct node*)malloc(sizeof(struct node));
        if(link->next==NULL)
        {
            printf("MEMORY NOT ALLOCATED");
            exit(0);
        }
        link=link->next;
        printf("Enter coefficient for degree %d : ",i);
        scanf("%d",&link->coeff);
        link->pow=i;
        link->next=NULL;
    }
}


void display(poly link)
{
    printf("Polynomial Representation : ");
    while(link!=NULL)
    {
        if(link->coeff >= 0)
            printf("+");
        printf("%dx^%d ",link->coeff,link->pow);
        link=link->next;
    }
}



main()
{
    int p;
    poly A;
    A=(struct node*)malloc(sizeof(struct node));
    if(A==NULL)
    {
        printf("MEMORY NOT ALLOCATED!");
        exit(0);
    }
    printf("Enter highest power of x : ");
    scanf("%d",&p);
    CreatePoly(A,p);
    display(A);
    return 0;

}
