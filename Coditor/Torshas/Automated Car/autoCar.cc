#include <bits/stdc++.h>
using namespace std;

#define lli long long int

void solve() {
    lli df = 0, dr = 0, sf = 0, sr = 0, sg = 0;
    lli time = 1;
    cin >> df >> dr >> sf >> sr >> sg;

    if(sf == sr) {
        if(df > sf) {
            if(dr > sr) {
                cout << "NO, Z, -1";
                exit(0);
            }
            else {
                if(sg == 0) {
                    cout << "NO, Z, -1";
                    exit(0);
                }
            }
        }
        else {
            if(sg == 1) {
                if(dr > sr) {
                    cout << "NO, Z, -1";
                    exit(0);
                }
            }
        }
    }
    while(1) {
        if(sg == 0) {
            df -= sf;
            dr += sf;
            if(df <= 0) {
                cout << "YES, F, " << time;
                break;
            }
            else {
                time += 1;
            }
            sg = 1;
        }
        else {
            dr -= sr;
            df += sr;
            if(dr <= 0) {
                cout << "YES, B, " << time;
                break;
            }
            else {
                time += 1;
            }
            sg = 0;
        }
    } 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}