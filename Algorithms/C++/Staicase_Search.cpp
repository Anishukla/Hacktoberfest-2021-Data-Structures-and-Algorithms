# Satircase Search algorithm is used to search element in a 2D matrix. If we use linear search algorithm then the time complexity will be O(N*N) but the time complexity of staicase search algorithm will be O(N). The only condition is that
staircase search algorithm is only applied on the sorted 2D array means both rows and columns of the 2D array will be sorted.



#include <iostream>
using namespace std;

int main()
{
   int n;
   cin>>n;
   
   int A[n][n];
   
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           cin>>A[i][j];
       }
   }
   int key;
   cin>>key;
   
   int r,i=0,j=n-1,flag=0; //starting with top right element
    
    while(i<n && j>=0)
    {
        r=A[i][j];
        if(key==r)
        {
            cout<<i+1<<" "<<j+1<<endl;
            return 0;
        }
        else if(key>r)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    
    
        cout<<"Element Not Found";

   
   return 0;
}