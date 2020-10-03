//Program to obtain the result of a taylor series expression: e^x = 1 + x/1! + x^2 / 2! + x^3 / 3!.....
// Contributor: Kavinraja-G
#include<stdio.h>

//By using Homer's Rule we perform the recursive multiplication at the ascending itsef:
double series(int x,int n)
{
    static double res;
    if(n==0)
        return res;
    else
    {
        res = 1+((x*res)/n);
        return series(x,n-1);
    }
}

// Driver Code
int main()
{
    int x=2,n=10;
    printf("%lf",series(x,n));
}