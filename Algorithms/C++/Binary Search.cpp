#include<bits/stdc++.h>
using namespace std;

int binary_search(int a[], int &n, int &target) {
	int l = -1, r = n;
	
	while(r > l + 1) {
		int m = l + (r - l) / 2; // tackles integer overflow
		
		if(a[m] >= target) r = m; // contracts the search region
		else l = m; // expands the search region
	}
	
	return r;
}

int main() {
	
	int a[] = {0, 4, 5, 7, 9, 21, 34, 4999};
	int n = sizeof(a) / sizeof(a[0]);
	int target = 7;
	cout << binary_search(a, n, target);
	return 0;
}