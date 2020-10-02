#include <bits/stdc++.h>

using namespace std;


// Considering 'n' is not equal to 0
int longest_inc_subsq(int nums[], int n){

	int max_length = 0;

	// Initializing LIS array and filling them all with 1
	vector<int> LIS(n,1);

	// This double loop fills the LIS array
	for(int i = 0; i <= n-1 ; i++){
		for(int j = 0; j <= i-1 ; j++){
			if( nums[i] > nums[j] && LIS[i] < LIS[j] + 1 )
				LIS[i] = LIS[j] + 1;
		}
	}

	// This loop just finds the maximum value among all the LIS[i] values
	for(int i = 0; i <= n-1 ; i++){
		if(max_length < LIS[i])
			max_length = LIS[i];
	}

	return max_length;
}

int main(){

	int nums[5] = {12, 24, 11, 38, 22};
	int n = sizeof(nums)/sizeof(nums[0]);
	
	printf("The length of longest increasing subsequence for the array [12, 24, 11, 38, 22] is : %d.", longest_inc_subsq(nums,n) );

	return 0;
}