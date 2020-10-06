/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);


// Optimal Segment Tree implementation with point update and range sum query.

// Segment Tree Template
template<typename t> 
class SegmentTree {
public:
	t n; // Size of array
	vector<t> tr, a; // tr is the segment tree and a is the main array.

	SegmentTree(vector<t> &a, t n) : a(a), n(n) { // Constructor for Segment tree template
		tr.resize((n << 1) | 1); // Resize the tree with  (2 * n + 1) size.
		for (t i = 0; i < n; i++) tr[n + i] = a[i]; // Assigning leaves of tree
		build(); // Calling build function to create segment tree.
	}

	void build() { // Build Function for tree
		for (t i = n - 1; i > 0; i--) 
			tr[i] = tr[i << 1] + tr[(i << 1) | 1];
	}

	void pointUpdate(t idx, t val) { // Point Update function
		// ids = Index to be updated
		// val = new value
		for (tr[idx + n] = val; idx > 1; idx >>= 1) 
			tr[idx >> 1] = tr[idx] + tr[idx ^ 1];
	}

	t rangeQuery(t start, t end) { // Range sum query
		// start = start index of required range
		// end = end of required range
		end++; // Upper bound of segment has to be exclusive
		t sum(0);
		for (start += n, end += n; start < end; start >>= 1, end >>= 1) {
			if (start & 1) sum += tr[start++];
			if (end & 1) sum += tr[--end];
		}
		return sum;
	}
};

void solve() {
	int sze; // size of array
	cin >> sze;
	vector<int> a(sze); // declaring array of given size
	for (int &i: a) cin >> i; // taking array input
	SegmentTree<int> tree(a, sze); // creating segment tree
	int query; // number of queries
	cin >> query; 
	for (int i = 0; i < query; i++) {
		string type; // type of query
		cin >> type;
		if (type == "Update") { // update call
			int idx, val;
			cin >> idx >> val;
			idx--;
			tree.pointUpdate(idx, val);
		}
		else { // sum query call
			int start, end;
			cin >> start >> end;
			start--, end--;
			cout << tree.rangeQuery(start, end) << "\n";
		}
	}
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}