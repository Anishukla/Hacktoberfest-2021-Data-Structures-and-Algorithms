/*
Algorithm:
1.Loop through each element and maintains a count of majority element, and a majority index(maj_index)
2. If the next element is same then increment the count if the next element is not same then decrement the count.
3. If the count reaches 0 then changes the maj_index to the current element and set the count again to 1.
4. Now again traverse through the array and find the count of majority element found.
5. If the count is greater than half the size of the array, print the element
6. Else print that there is no majority element
*/

// It is used to find the majority element in an array

#include <iostream>
using namespace std;

void majElement(int arr[], int n) //4 5 5 2 5 1 5 6
{
    int count = 1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[res])
        {
            count++;
        }
        else
            count--;
        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[res])
        {
            count++;
        }
    }

    if (count <= n / 2)
        cout << "No majority element" << endl;
    else
        cout << "Majority element: " << arr[res] << endl;
}

int main()
{
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    majElement(arr, n);
    return 0;
}
