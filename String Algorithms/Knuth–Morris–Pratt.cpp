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

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string a, b;
    cin >> a >> b; // We are trying to find string B in string A
    int MOD = 10007;
    int N = a.size(), M = b.size(), d = 256, i, j;
    int hashA = 0, hashB = 0, h = 1;
    for (i = 0; i < M-1; i++) h = (h * d) % MOD;
    for (i = 0; i < M; i++) {
        hashB = (d * hashB + b[i]) % MOD;
        hashA = (d * hashA + a[i]) % MOD;
    }
    for (i = 0; i <= N - M; i++) {
        if (hashA == hashB) {
            for (j = 0; j < M; j++) {
                if (a[i+j] != b[j]) break;
            }
            if (j == M) {
                cout << i << ell;
                return 0;
            }
        }
        if (i < N - M) {
            hashA = (d * (hashA - a[i] * h) + a[i+M]) % MOD;
            if (hashA < 0) hashA = (hashA + MOD);
        }
    }
    cout << -1 << ell;
}
