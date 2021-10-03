/*Created by Lakshay Goel
  Github Profile link: https://github.com/MrLakshay

  This program is to find Fibonacci series using for loop 
  Time complexity of the problem is O(n)
*/
#include <iostream>  
using namespace std;  
int main() {    
  int a=0,b=1,c,i,number; //intializing the fist and second digit of the series    
  cout<<"Enter the number of elements: ";    
  cin>>number;    //taking input
  cout<<a<<" "<<b<<" ";  //outputing first two digit irrespective of given input
  for(i=2;i<number;++i)     //only works if input is greater than 2
  {    
    c=a+b;    
    cout<<c<<" ";    
    a=b;    
    b=c;    
  }    
  return 0;  
}  
/*Sample test case:
  7
  0 1 1 2 3 5 8 
*/
