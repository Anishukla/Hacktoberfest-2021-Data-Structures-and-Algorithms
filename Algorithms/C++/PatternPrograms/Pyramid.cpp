#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter Number of Rows : ";
    cin>>n;
    for(int i=1, k=0; i<=n; i++, k=0)
    {
        for(int j=1; j<=(n-i); j++)
        {
            cout<<" ";
        }
        while(k!=(2*i)-1)
        {
            cout<<"*";
            k++;
        }
        cout<<endl;
    }
    return 0;
}
