//Aditya Singh Rathore
//Time Complexity =O[n^2]
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the size of array\n";
    cin>>n;
    int a[n];
    cout<<"Enter the Ele\n";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int c=1;
    while(c<n){
        for(int i=0;i<(n-c);i++){
            if(a[i]>a[i+1]){
                int t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
        }
        c++;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
}
