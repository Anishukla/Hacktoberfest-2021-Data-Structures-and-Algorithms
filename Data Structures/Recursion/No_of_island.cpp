/*You are given a 2-dimensional array/list having N rows and M columns, which is filled with ones(1) and zeroes(0). 1 signifies land, and 0 signifies water.
A cell is said to be connected to another cell, if one cell lies immediately next to the other cell, in any of the eight directions (two vertical, two horizontal, and four diagonals).
A group of connected cells having value 1 is called an island. Your task is to find the number of such islands present in the matrix.
Input  - N X M  mmatrix */

#include <iostream>
#include <vector>
using namespace std;
//check whether land is safe or not
bool isSafe(int N,int M,int i,int j)
{
    // below zero index and after or at nth index cannot be accesible , so it is not safe
	if(i < 0 || i >= N)
		return false;
    //below zero index and after or at mth index cannot be accesible , so it is not safe
	if(j < 0 || j >= M)
		return false;
	return true;
}

//this function does the DFS for every new one 1 found and assign every connected one to zero.
void help(int** arr,int n,int m,int i,int j)
{
    //check if it is safe and it is land or not
	if(isSafe(n,m,i,j) && arr[i][j] == 1)
		{
            // if so 1 i.e. there is land then make it 0,so that we cannot add it again 
			arr[i][j] = 0;
            //recursive function to check land in all possible direction
			help(arr, n, m , i-1, j-1);
			help(arr, n, m, i-1, j);
			help(arr, n, m, i-1, j+1);
			help(arr, n, m, i, j-1);
			help(arr, n, m, i, j+1);
			help(arr, n, m, i+1, j-1);
			help(arr, n, m, i+1, j);
			help(arr, n, m, i+1, j+1);
		}
}
int getTotalIslands(int** arr, int n, int m)
{
    //initialize count as 0
    int count = 0 ;
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
            //if there is land
				if(arr[i][j] == 1)
					{
                        //increase count 
						count++;
                        //check its surrounding
						help(arr,n,m,i,j);
					}
		}
    //return count
	if(count == 0)
		return 0;
	return count;
}
//main function 
int main()
{
    int n, m;
    cin >> n >> m;

    int **arr = new int *[n];
    for(int i=0; i<n; i++) arr[i] = new int[m];
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Number of island is::"getTotalIslands(arr, n, m) << endl;

    for(int i=0; i<n; i++) delete[] arr[i];
    delete[] arr;

    return 0;
}
//Tanisha Hisariya