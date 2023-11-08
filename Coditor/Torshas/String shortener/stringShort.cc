#include <bits/stdc++.h>
using namespace std;

#define lli long long int

void solve() {
    string s;
    lli cnt = 0;
    cin >> s;
    if(s.length() <1 || s.length() > 100) {
        exit(1);
    }
    while(true) {
        lli current = -1, next = -1, flag = 0;
        for(lli i = 0; i < s.length(); i++) {
            if(s[i] != '@') {
                current = i;
                for(lli j = i + 1; j < s.length(); j++) {
                    if(s[j] != '@') {
                        next = j;
                        break;
                    }
                }
                if((s[current] == s[next]) && (current != next)) {
                    s[current] = '@';
                    s[next] = '@';
                    flag = 1;
                }
            }
        }
        if(flag == 0) {
            break;
        } 
    }
    for(lli i = 0; i < s.length(); i++) {
        if(s[i] != '@') {
            cnt += 1;
            cout << s[i];
        }
    }
    if(cnt == 0) {
        cout << "Empty String";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}