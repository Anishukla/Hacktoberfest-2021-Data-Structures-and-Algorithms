#include<iostream>
using namespace std;

void selectionSort(int a[],int size);
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

    selectionSort(arr,n);

    cout<<"\nFinal Sorted (ascending) Array : \n";
    printArray(arr,n);

    return 0;
}


void selectionSort(int a[],int size){
    int min;
    for(int i=0;i<size-1;i++){
        min=i;
        for(int j=i+1;j<size;j++){
            if(a[min]>a[j]){
                min=j;
            }
        }
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}

void printArray(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<"   ";
    }
}