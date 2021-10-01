# Insertion is the one of the basic sorting algorithm used to sort array elements. TIme Complexity O(N^2)


#include <iostream>
using namespace std;

int main()
{
   int n;
   cin>>n;
   
   int A[n];
   
     for(int j=0;j<n;j++)
       {
           cin>>A[j];
       }
      
      for(int i=1;i<n;i++)
      {
          int k=A[i];
          int j=i-1;
          
          while(j>=0 && A[j]>k)
          {
              A[j+1]=A[j];
              j=j-1;
          }
          A[j+1]=k;
      }
      for(int j=0;j<n;j++)
       {
           cout<<A[j]<<" ";
       }
   return 0;
}