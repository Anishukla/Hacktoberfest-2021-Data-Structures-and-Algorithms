#include <stdio.h>
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int l, int r)
{
    int piviot = arr[r];
    int i = l - 1;
    for (int j = 1; j < r; j++)
    {
        if (arr[j] < piviot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}
void quicksort(int arr[], int l, int r)//   8 9 6 | 4 3 2 
{
    int pi = partition(arr, l, r);
    quicksort(arr, l, pi - 1);
    quicksort(arr, pi + 1, r);
}
int main(){
    int arr[5]={5,2,3,1,4};
    quicksort(arr,0,4);
    for (int i = 0;i<5;i++){
        printf("%d ",arr[i]);
    }

}