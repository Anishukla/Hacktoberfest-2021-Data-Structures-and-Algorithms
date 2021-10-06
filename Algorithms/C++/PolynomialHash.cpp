#include <bits/stdc++.h>

#define mod 1000000007
using namespace std;

typedef long long ll;
vector<ll> hsh, pw;

const int base = 131; // Pick a prime number, preferably larger

// Returns hash value from l - > r (inclusive)
ll getSubHash(int l, int r){
    ll v1 = (hsh[r] - hsh[l-1] * pw[r-l+1] % mod + mod) % mod;
    return v1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; // string
    cin >> s;
    int n = s.size();
    hsh.resize(n+1), pw.resize(n+1);
    hsh[0] = 0, pw[0] = 1;
    for (int i = 0; i < n; i++){
        hsh[i+1] = (hsh[i]*base + s[i]) % mod;
        pw[i+1] = pw[i]*base%mod;
    }
    // cout << getSubHash(1, 1) << "\n";
}
