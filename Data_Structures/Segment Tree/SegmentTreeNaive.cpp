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


// Naive Segment Tree implementation with point update and range sum query.


// Segment Tree Template
template<typename t> 
class SegmentTree {
public:
	t n; // Size of array
	vector<t> tr, a; // tr is the segment tree and a is the main array.

	SegmentTree(vector<t> &a, t n) : a(a), n(n) { // Constructor for Segment tree template
		tr.resize((n << 2) | 1); // Resize the tree with  (4 * n + 1) size.
		build(1, 0, n - 1); // Calling build function to create segment tree.
	}

	void build(t p, t low, t high) { // Build Function for tree
		// p = index of segment tree responsible for the particular segment from low to high of array
		// low = start index of array segment
		// high = last index of array segment
		if (low > high) return; // Break point for recursive build
		if (low == high) { // Base case (leaf of segment tree)
			tr[p] = a[low]; // Assign value to leaf
			return;
		}
		t mid = (low + high) >> 1; // Mid point of array segment
		build(p << 1, low, mid); // Build left subsegment
		build((p << 1) | 1, mid + 1, high); // Build right subsegment
		tr[p] = tr[p << 1] + tr[(p << 1) | 1]; // Merging left and right subsegment
	}

	void pointUpdate(t p, t low, t high, t idx, t val) { // Point Update for segment tree
		// p = index of segment tree responsible for the particular segment from low to high of array
		// low = start index of array segment
		// high = last index of array segment
		// idx = index to be upated in array
		// val = new value to be updated
		if (low > idx or high < idx or low > high) return; // Break point of recursion
		if (low == high and low == idx) { // Base case of recursion
			tr[p] = val; // Update the value at leaf of tree
			return;
		}
		t mid = (low + high) >> 1; // Mid point of array segment
		// Check if the update point is in left or right subsegment 
		// Update accordingly
		if (idx <= mid) pointUpdate(p << 1, low, mid, idx, val); 
		else pointUpdate((p << 1) | 1, mid + 1, high, idx, val);
		tr[p] = tr[p << 1] + tr[(p << 1) | 1]; // Merging the array once again after update
	}

	t rangeQuery(t p, t low, t high, t start, t end) { // Query for range sum
		// p = index of segment tree responsible for the particular segment from low to high of array
		// low = start index of array segment
		// high = last index of array segment
		// start = start index of the query segment
		// end = end index of the query segment
		if (low > end or start > high or low > high) return 0; // Break point
		if (start <= low and end >= high) return tr[p]; // Base case (when query overlaps the complete given array segment)
		int mid = (low + high) >> 1; // Finding mid of array segment
		return (rangeQuery(p << 1, low, mid, start, end) + rangeQuery((p << 1) | 1, mid + 1, high, start, end)); // Merging left and right queries.
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
			tree.pointUpdate(1, 0, sze - 1, idx, val);
		}
		else { // sum query call
			int start, end;
			cin >> start >> end;
			start--, end--;
			cout << tree.rangeQuery(1, 0, sze - 1, start, end) << "\n";
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