// C++ code to get count of a particular pattern in a text string

// Sample Input:
// ac acbdac

// Sample Output:
// 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
	// intialise pattern and text string
	string p, t;
	cin >> p >> t;

	string mod = p + '#' + t;
	int n = t.length(), m = p.length();

	// create Z array
	int *z = (int *)malloc((n + m) * sizeof(int));
	z[0] = 0;

	// l and r are constants to maintain the interval [l, r] such that t[l...r] = p
	int l = 0, r = 0, cnt = 0;

	// Search for pattern
	for (int i = 1; i < n + m + 1; i++)
	{
		// if i > r, then no substring is present
		// reset l and r to i and find the interval again
		if (i > r)
		{
			l = r = i;
			while (r < n + m + 1 && mod[r - l] == mod[r])
				r++;
			z[i] = r - l;
			r--;
		}

		// if i < r then there is an interval [l, r] in pattern for atleast r-i+1 characters
		else
		{
			int k = i - l;
			if (z[k] < r - i + 1)
				z[i] = z[k];

			else
			{
				l = i;
				while (r < n + m + 1 && mod[r - l] == mod[r])
					r++;
				z[i] = r - l;
				r--;
			}
		}
		if (z[i] == m)
			cnt++;
	}
	cout << cnt << "\n";
	free(z);
	return 0;
}