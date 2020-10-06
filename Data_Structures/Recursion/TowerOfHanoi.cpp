#include "bits/stdc++.h"
using namespace std;

//Topic - Recursion
//Code Problem - Tower of Hanoi
//Complexity - O(2^n)

void towerOfHanoi(char source, char aux, char dest, int numberOfDisks) {
	//Move 1 disk from source to destination
	if (numberOfDisks == 1) {
		cout<< "Move " << numberOfDisks <<" from " << source << " to "<< dest <<endl;
		return;
	}
	//Move n-1 disks from source peg to auxiliary peg
	towerOfHanoi(source, dest, aux, numberOfDisks-1);
	//Move nth disk from source peg to destination peg
 	cout<<"Move " << numberOfDisks << " from " << source << " to " << dest <<endl;
 	//Move n-1 disks from auxiliary peg to destination peg
	towerOfHanoi(aux, source, dest, numberOfDisks-1);
}


int main() {
	char source = 'A', aux = 'B', dest = 'C';
	int numberOfDisks = 3;
	towerOfHanoi(source, aux, dest, numberOfDisks);
	return 0;
}