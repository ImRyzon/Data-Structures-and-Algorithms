#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define vt vector
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

void solve() {
    int N, K, num; cin >> N >> K >> num;
    deque<pii> dq;
    dq.eb(0, num);
    for (int i = 1; i < N; i++) {
        cin >> num;
        while (!dq.empty() && i - dq.front().first > K) dq.popf();
        int cur = num + dq.front().second;
        while (!dq.empty() && cur < dq.back().second) dq.popb();
        dq.eb(i, cur);
    }
    cout << dq.back().second << ell;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int TEST_CASES = 1;
    for (int i = 1; i <= TEST_CASES; i++) solve();
}
