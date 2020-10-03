// Contributor: Kavinraja-G
#include<stdio.h>
#include<stdlib.h>

//Tail Type recursive function
int sum(int n)
{
    if(n==0)
        return 0;
    else
        return sum(n-1)+n; 
}

// Driver Code
int main()
{
    int n = 15;
    printf("%d",sum(n));
}