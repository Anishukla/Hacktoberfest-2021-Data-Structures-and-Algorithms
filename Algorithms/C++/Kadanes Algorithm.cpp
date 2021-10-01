# Kadane's Algorithm is used to find the maximum subarray sum in O(N) time complexity. Usually time complexity of finding maximum array sum is O(N^3).


#include<iostream>
using namespace std;
int main() {
	int t;//here t is number of test cases
	cin>>t;
	while(t--)
	{
		int n; //length of the array
		cin>>n;
		int A[n];
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
		int CS=0,MS=0;

		for(int i=0;i<n;i++)
		{
			CS+=A[i];
			if(CS<0)
				CS=0;
			MS=max(CS,MS);
		}
		cout<<MS<<endl;
	}
	return 0;
}