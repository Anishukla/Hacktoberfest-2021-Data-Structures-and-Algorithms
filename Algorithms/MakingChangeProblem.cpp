#include <iostream>
#include <climits>
using namespace std;
int findMinCoins(int S[], int n, int N)
{
	if (N == 0)
		return 0;
	// return INFINITY if total become negative
	if (N < 0)
		return INT_MAX;
	// initialize minimum number of coins needed to infinity
	int coins = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		// recur to see if total can be reached by including
		// current coin S[i]
		int res = findMinCoins(S, n, N - S[i]);

		// update minimum number of coins needed if choosing current
		// coin resulted in solution
		if (res != INT_MAX)
			coins = min(coins, res + 1);
	}
	return coins;
}

int main()
{
    int n,a,den[10];
	cout<<"enter the no of denominations: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>den[i];
	}
	cout<<"enter the amount you want to withdraw: ";
	cin>>a;
    int coins = findMinCoins(den, n, a);
    if (coins != INT_MAX)
		cout << "Minimum number of coins required to get desired change is-"<< coins;

	return 0;
}
