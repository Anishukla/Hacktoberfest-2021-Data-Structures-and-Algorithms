#include<iostream>
using namespace std;

void bubbleSort(int a[],int size);
void printArray(int a[],int size);

int main(){

    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter the array to be sorted : \n";

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"\nInitial Array : \n";
    printArray(arr,n);

    bubbleSort(arr,n);

    cout<<"\nFinal Sorted (ascending) Array : \n";
    printArray(arr,n);

    return 0;
}


void bubbleSort(int a[],int size){
    int temp=0;
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]>a[j]){
                //do swapping
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}

void printArray(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<"   ";
    }
}