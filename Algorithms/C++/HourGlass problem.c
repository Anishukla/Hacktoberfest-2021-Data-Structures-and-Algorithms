// Given a 6x6 2D array, arr:-
// 1 1 1 0 0 0
// 0 1 0 0 0 0
// 1 1 1 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// We define an hourglass in A to be a subset of values with indices falling in this pattern in arr's graphical representation:

// a b c
  // d
// e f g

// There are 16 hourglasses in arr, and an hourglass sum is the sum of an hourglass' values. 
// Calculate the hourglass sum for every hourglass in arr, then print the maximum hourglass sum.

// For example, given the 2D array:

// -9 -9 -9  1 1 1 
 // 0 -9  0  4 3 2
// -9 -9 -9  1 2 3
 // 0  0  8  6 6 0
 // 0  0  0 -2 0 0
 // 0  0  1  2 4 0
// We calculate the following 16 hourglass values:

// -63, -34, -9, 12, 
// -10, 0, 28, 23, 
// -27, -11, -2, 10, 
// 9, 17, 25, 18

// Our highest hourglass value is 28 from the hourglass:
// 0 4 3
  // 1
// 8 6 6

// Function Description

// Complete the function hourglassSum in the editor below. It should return an integer, the maximum hourglass sum in the array.

// hourglassSum has the following parameter(s):

// arr: an array of integers

// Sample Input

// 1 1 1 0 0 0
// 0 1 0 0 0 0
// 1 1 1 0 0 0
// 0 0 2 4 4 0
// 0 0 0 2 0 0
// 0 0 1 2 4 0
// Sample Output

// 19



#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

// Complete the hourglassSum function below.
int hourglassSum(int arr_rows, int arr_columns, int** arr) 
{
    int i,j;
    int max = arr[0][0]+arr[0][1]+arr[0][2]+arr[1][1]+arr[2][0]+arr[2][1]+arr[2][2];
    int sum;
    for(i=0;i<arr_rows-2;i++)
    {
        for(j=0;j<arr_columns-2;j++)
        {
            sum=0;
            sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] +
                arr[i+2][j+1] + arr[i+2][j+2];
            if(sum>max)
                max=sum;
        }
    }
    return max;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int** arr = malloc(6 * sizeof(int*));

    for (int i = 0; i < 6; i++) {
        *(arr + i) = malloc(6 * (sizeof(int)));

        char** arr_item_temp = split_string(readline());

        for (int j = 0; j < 6; j++) {
            char* arr_item_endptr;
            char* arr_item_str = *(arr_item_temp + j);
            int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

            if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(*(arr + i) + j) = arr_item;
        }
    }

    int arr_rows = 6;
    int arr_columns = 6;

    int result = hourglassSum(arr_rows, arr_columns, arr);

    fprintf(fptr, "%d\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
