#include <bits/stdc++.h>
using namespace std;

#define lli long long int

void solve() {
    lli l, cnt = 0;
    cin >> l;
    lli arr[l];
    for(lli i = 0; i < l; i++) {
        cin >> arr[i];
    }

    while(true) {
        lli current = -1, next = -1, flag = 0;
        for(lli i = 0; i < l; i++) {
            if(arr[i] != -1) {
                current = i;
                for(lli j = i + 1; j < l; j++) {
                    if(arr[j] != -1) {
                        next = j;
                        break;
                    }
                }
                if(arr[current] == arr[next] && current != next) {
                    arr[current] = -1;
                    arr[next] = -1;
                    flag = 1;
                }
            }
        }
        if(flag == 0) {
            break;
        }
    }
    for(lli i = 0; i < l; i++) {
        if(arr[i] != -1) {
            cnt += 1;
        }
    }
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}