#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
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

void solve() {
    int N, M, C;
    scan(N); scan(M); scan(C);
    deque<pii> mx, mi;
    for (int i = 0, a; i < N; i++) {
        scan(a);
        while ((!mx.empty() && mx.front().second <= i - M) || (!mi.empty() && mi.front().second <= i - M)) {
            if (!mx.empty() && mx.front().second <= i - M) mx.popf();
            if (!mi.empty() && mi.front().second <= i - M) mi.popf();
        }
        while ((!mx.empty() && mx.back().first < a) || (!mi.empty() && mi.back().first > a)) {
            if (!mx.empty() && mx.back().first < a) mx.popb();
            if (!mi.empty() && mi.back().first > a) mi.popb();
        }
        mx.eb(a, i); mi.eb(a, i);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int TEST_CASES = 1;
    for (int i = 1; i <= TEST_CASES; i++) solve();
}
