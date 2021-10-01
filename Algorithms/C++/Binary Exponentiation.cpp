#include<bits/stdc++.h>
using namespace std;

int binaryExpo(int a, int b) {
	int res = 1;
	
	while(b > 0) {
		if(b & 1) res = res * a; // if b is odd
		b >>= 1; // divide by 2
		a = a * a;
	}
	
	return res;
}

int main() {
	
	int a = 2;
	int b = 10;
	cout << binaryExpo(a, b);
	return 0;
}