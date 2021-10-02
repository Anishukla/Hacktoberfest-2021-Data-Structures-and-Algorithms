#include<iostream>
using namespace std;

void insertionSort(int a[],int size);
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

    insertionSort(arr,n);

    cout<<"\nFinal Sorted (ascending) Array : \n";
    printArray(arr,n);

    return 0;
}


void insertionSort(int a[],int size){
    int toInsert;
    for(int i=1;i<size;i++){
        toInsert=a[i];
        int j;
        for(j=i-1;j>=0 and a[j]>toInsert;j--){
           a[j+1]=a[j];
        }
        a[j+1]=toInsert;
    }
}

void printArray(int a[],int size){
    for(int i=0;i<size;i++){
        cout<<a[i]<<"   ";
    }
}