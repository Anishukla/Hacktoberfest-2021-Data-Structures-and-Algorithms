#include <bits/stdc++.h>
using namespace std;

#define lli long long int

void solve() {
    lli n = 1, k = 1, m = 1, max = 0, maxInd = 0, sum = 0;
    cin >> n >> k >> m;
    lli a[n], b[n];
    for(lli i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(lli i = 0; i < n; i++) {
        cin >> b[i];
    }

    max = abs(b[0]);
    for(lli j = 1; j < n; j++) {
        if(abs(b[j]) > max) {
            max = abs(b[j]);
            maxInd = j;
        }
    }
    if(b[maxInd] < 0) {
        a[maxInd] += (k*m);
    }
    else if(b[maxInd] > 0) {
        a[maxInd] -= (k*m);
    }
    for(lli j = 0; j < n; j++) {
        sum += a[j] * b[j];
    }    
    cout << sum << "\n";   

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T, i = 1;
    cin >> T;
    while(T--) {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }

    return 0;
}