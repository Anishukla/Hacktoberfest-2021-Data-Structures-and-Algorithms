// Dutch National Flag Problem
// Time Complexity: O(N)
// Problem: Sort an array having elements 0,1,2
// Solution:
#include <bits/stdc++.h>
#define boost ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

void sortArray(int arr[], int n)
{
    int low = 0;
    int high = n-1;
    int mid = 0;
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            sortArray(arr, mid-1);   
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }   
    }
}

// Execute Code
int main()
{
    boost;
    
    // Input array size
    int n;
    cin >> n;

    // Input array elements
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    
    // Sort the array
    sortArray(a, n);

    // Output sorted array
    for(int i=0;i<n-1;i++) cout << a[i] << " ";
    cout << a[n-1] << "\n";
    return 0;
}

// Contributed by Ruban Sahoo (https://github.com/kaitou-1412)