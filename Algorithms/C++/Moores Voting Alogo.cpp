#include<bits/stdc++.h>
using namespace std;

int MooresAlgo(int a[], int &n) {
    int count = 0;
    int cand = 0;
    
    for(int i = 0; i < n; i++) {
        if(count == 0)
            cand = a[i];
        
        if(a[i] == cand) count++;
        else count--;
    }
    
    return cand;
}

int main() {
	
	int a[] = {2,2,1,1,1,2,2};
	int n = sizeof(a) / sizeof(a[0]);
	
	cout << MooresAlgo(a, n);
	return 0;
}