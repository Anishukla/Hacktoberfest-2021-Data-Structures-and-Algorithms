//Program to find the number of Combinations recursively:
// Contributor: Kavinraja-G
/* Usually the combinations can be obtained from the Pascal's Triangle based on the level
the combinations grows. Hence we derived a formula for calculating the nCr recursively.
====================== nCr = (n-1)C(r-1) + (n-1)Cr =================================== */

#include<stdio.h>

// Implementing the formula
double nCr(int n,int r)
{
    if( r==0 || n==r)
        return 1;
    else
    {
        return nCr(n-1,r-1)+nCr(n-1,r);
    }
}

// Driver Code
int main()
{
    int n,r;
    printf("%f",nCr(5,2));
}