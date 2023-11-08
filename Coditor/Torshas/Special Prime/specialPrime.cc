#include <bits/stdc++.h>
using namespace std;

#define lli long long int

lli primeCheck(lli n) {
    lli flag = 0;
    for(lli i = 2; i < n; i++) {
        if(n%i == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}

void solve() {
    lli n, s = 2, c = 0;
    cin >> n;
    for(lli i = 3; i <= n; i++) {
        if(primeCheck(i) == 0) {
            s += i;
            if(s > n) break;
            else {
                if(primeCheck(s) == 0) {
                    c += 1;
                }
            }
        }
    }
    cout << c << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}