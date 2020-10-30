// Rajshree Mondal github: rajshree2000

/* Maximum size subset with given sum using Backtracking
Given an array arr[] consisting of N integers and an integer K, the task is to find the length of the longest subsequence with a sum equal to K.
Recursive & Backtracking Approach: The basic approach of this problem is to sort the vector and find the sum of all the possible subsequences and pick up the subsequence with the maximum length having the given sum. This can be done using Recursion and Backtracking.

Follow the steps below to solve this problem:  

Sort the given array/vector.
Initialize a global variable max_length to 0, which stores the maximum length subset.
For every index i in the array, call the recursion function to find out all the possible subsets with elements in the range [i, N-1] having sum K.
Every time a subset with sum K is found, check if its size is greater than the current max_length value. If yes, then update the value of max_length.
After all the possible subset sums are computed, return the max_length.
*/

// Java Program to implement the above approach
import java.util.*;
class GFG{

// Initialise maximum possible
// length of subsequence
static int max_length = 0;

// Store elements to compare
// max_length with its size
// and change the value of
// max_length accordingly
static Vector<Integer> store = new Vector<Integer>();

// Store the elements of the
// longest subsequence
static Vector<Integer> ans = new Vector<Integer>();

// Function to find the length
// of longest subsequence
static void find_max_length(
	int []arr,
	int index, int sum, int k)
{
	sum = sum + arr[index];
	store.add(arr[index]);
	if (sum == k) 
	{
		if (max_length < store.size()) 
		{
			// Update max_length
			max_length = store.size();

			// Store the subsequence
			// elements
			ans = store;
		}
	}

	for (int i = index + 1;
			i < arr.length; i++) 
	{
		if (sum + arr[i] <= k) 
		{

			// Recursively proceed
			// with obtained sum
			find_max_length(arr, i,
							sum, k);

			// poping elements
			// from back
			// of vector store
			store.remove(store.size() - 1);
		}

		// if sum > 0 then we don't
		// required thatsubsequence
		// so return and continue
		// with earlier elements
		else
			return;
	}
	return;
}

static int longestSubsequence(int []arr,
								int n, int k)
{

	// Sort the given array
	Arrays.sort(arr);

	// Traverse the array
	for (int i = 0; i < n; i++) 
	{
		// If max_length is already
		// greater than or equal
		// than remaining length
		if (max_length >= n - i)
			break;

		store.clear();

		find_max_length(arr, i, 0, k);
	}
	return max_length;
}

// Driver code
public static void main(String[] args)
{
	int []arr = { -3, 0, 1, 1, 2 };
	int n = arr.length;
	int k = 1;

	System.out.print(longestSubsequence(arr,
										n, k));
}
}

