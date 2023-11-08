#include <iostream>
using namespace std;

void printPairs(int a[], int size, int target);

int main()
{

    int n;
    cout << "Enter the size of array : ";
    cin >> n;

    int arr[n];
    cout << "\nEnter the array elements : \n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cout << "\nEnter the target sum : ";
    cin >> target;

    cout << "\nThe required pairs are : \n";
    printPairs(arr, n, target);

    return 0;
}

void printPairs(int a[], int size, int target)
{

    int start = 0;
    int end = size - 1;

    while (start < end)
    {
        int sum = a[start] + a[end];
        if (sum == target)
        {
            cout << a[start] << "     " << a[end] << endl;
            start++;
            end--;
        }
        else if (sum < target)
        {
            start++;
        }
        else if (sum > target)
        {
            end--;
        }
    }
}