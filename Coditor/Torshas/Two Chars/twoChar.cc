#include <bits/stdc++.h>
using namespace std;

#define lli long long int

void solve() {
    lli n = 0, max = 0, i = 0, j = 0, current = 0, cnt = 0;
    char ch1, ch2;
    string s;

    cin >> n;
    cin >> s;

    for(i = 0; i < 26; i++) {
        for(j = i + 1; j < 26; j++) {
            ch1 = (char)((int)'a' + i);
            ch2 = (char)((int)'a' + j);
            current = -1;
            cnt = 0;
            for(lli z = 0; z < n; z++) {
                if(s[z] == ch1) {
                    if(current == 1) {
                        current = -1;
                        break;
                    }
                    current = 1;
                    cnt++;
                }
                else if(s[z] == ch2) {
                    if(current == 2) {
                        current = -1;
                        break;
                    }
                    current = 2;
                    cnt++;
                }
            }
            if(current != -1 && cnt > 1 && cnt > max) {
                max = cnt;
            }
        }
    }
    cout << max << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}