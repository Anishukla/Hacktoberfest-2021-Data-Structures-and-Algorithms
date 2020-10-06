#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter no. of element:";
    cin >> n;
    vector<int> v(n, 0);
    map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]]++;
    }
    for (auto it = m.begin(); it != m.end(); it++)
        while (it->second--)
            ans.push_back(it->first);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}

