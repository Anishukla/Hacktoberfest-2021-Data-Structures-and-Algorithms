// author : @akashksinghal 
// Akash Kumar Singhal
#include <bits/stdc++.h>
using namespace std;
#define N 101
int A[N][N], I[N][N];

// To Print Matrix
void printMatrix(int A[][N], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}

void multiMatrix(int A[][N], int B[][N], int dim)
{
    int res[N + 1][N + 1];
    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < dim; k++)
            {
                res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    //Storing Calculated result in Identity Matrix of power function.
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            A[i][j] = res[i][j];
}

void power(int A[][N], int dim, int n)
{

    // Creating Identity Matrix of order dim
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            if (i == j)
                I[i][j] = 1;
            else
                I[i][j] = 0;

    /* Linear Complexity of O(n*n^3) ==> O(n^3*log(n))
    for(int i=0;i<n;i++){
        // Performing I = I*A n times.
        multiMatrix(I,A,dim);
    }
    */

    // Overall Complexity would be O(n^3*log(n))
    while (n)
    {
        if (n % 2)
        {
            multiMatrix(I, A, dim);
            n--;
        }
        else
        {
            multiMatrix(A, A, dim);
            n >>= 1;
        }
    }

    //Storing Calculated result in Matrix A from Identity Matrix
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            A[i][j] = I[i][j];
}

int main()
{
    // t -> no. of testcases
    // n -> power to which matrix needs to be raised
    // dim -> degree of matrix
    int t, n, dim;
    cin >> t;
    while (t--)
    {
        cin >> dim >> n;
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
                cin >> A[i][j];
        }
        power(A, dim, n);
        // Required Matrix
        printMatrix(A, dim);
    }
}