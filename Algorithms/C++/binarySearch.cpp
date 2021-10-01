#include <iostream>
using namespace std;

int binarySearch(int arr[],int n,int target)
{
	int left = 0;
    int right = n;
    

    while (left<= right)
    {
        int mid=int (left+right)/2;
        if (arr[mid]== target)
        {
            return mid;
        }
        
        else if(target < arr[mid])
        {
            right = mid-1;
        }
        
        else{
			left = mid+1;
		}
	}
        
    return -1;
        
        

    
}

int main()
{
    int n;
    cout<<"No of elements : ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    int target;
    cout<<"no to find : ";
    cin>>target;

	cout<<"Found At index : "<<binarySearch(arr,n,target);
    
    return 0;

    

}


