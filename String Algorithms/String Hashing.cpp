// This program is based off of CCC '20 S3 - Searching for Strings
// Link: https://dmoj.ca/problem/ccc20s3

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define pf push_front
#define ef emplace_front
#define eb emplace_back
#define emp emplace
#define popf pop_front
#define popb pop_back
#define mp make_pair
#define umap unordered_map
#define uset unordered_set
#define fill(x, a) memset(x, a, sizeof(x))
#define all(c) (c).begin(), (c).end()
#define sizeArr(t) (sizeof(t)/sizeof((t)[0]))
#define ell '\n'
#define scan(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MM = 2e5 + 5, base = 131, base2 = 10007, mod = 1e9 + 7;
ll hsh[MM], pw[MM], hsh2[MM], pw2[MM];
string s, t;
vector<int> fs(26), ft(26);
uset<ll> st;

ll getSubHash(int l, int r) {
    ll v1 = (hsh[r] - hsh[l-1] * pw[r-l+1] % mod + mod) % mod;
    ll v2 = (hsh2[r] - hsh2[l-1] * pw2[r-l+1] % mod + mod) % mod;
    return (v1 << 31) | v2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for (char c : s) fs[c - 'a']++;
    pw[0] = 1; pw2[0] = 1;
    for (int i = 1; i <= m; i++) {
        pw[i] = pw[i-1] * base % mod;
        hsh[i] = (hsh[i-1] * base + t[i-1]) % mod;
        pw2[i] = pw2[i-1] * base2 % mod;
        hsh2[i] = (hsh2[i-1] * base2 + t[i-1]) % mod;
    }
    for (int i = 1; i <= m; i++) {
        ft[t[i-1] - 'a']++;
        if (i > n) ft[t[i-n-1] - 'a']--;
        if (fs == ft) st.insert(getSubHash(i-n+1, i));
    }
    printf("%d\n", st.size());
}
