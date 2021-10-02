#include <bits/stdc++.h>
using namespace std;

#define lli long long int

void solve() {
    lli n, b, cnt = 0, cst = 0, max = 0, diff = 0, index = 0;
    cin >> n >> b;
    lli p[n];
    for(lli i = 0; i < n; i++) {
        cin >> p[i];
    }
    while(true) {
        max = 0;
        for(lli i = 0; i < n; i++) {
            if(p[i] != -1) {
                diff = b - p[i];
                if(diff > max) {
                    max = diff;
                    index = i;
                }
            }
        }
        if((cst + p[index]) > b) {
            cout << cnt << "\n";
            break;
        }
        else {
            cst += p[index];
            cnt += 1;
            p[index] = -1;
            if(cnt == n) {
                cout << cnt << "\n";
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    lli t, i = 1;
    cin >> t;
    while(t--) {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }

    return 0;
}