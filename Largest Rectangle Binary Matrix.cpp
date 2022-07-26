#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define vt vector
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define emp emplace
#define popf pop_front
#define popb pop_back
#define mp make_pair
#define umap unordered_map
#define fill(x, a) memset(x, a, sizeof(x))
#define all(c) (c).begin(), (c).end()
#define sizeArr(t) (sizeof(t)/sizeof((t)[0]))
#define ell "\n"
#define scan(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

void solve() {
    int R, C, ans = 0; cin >> R >> C;
    short grid[R][C]; int dp[C];
    for (int r = 0; r < R; r++) {
        stack<int> s;
        for (int c = 0; c < C; c++) {
            cin >> grid[r][c];
            if (r == 0) dp[c] = 0;
            dp[c] = (grid[r][c] == 0 ? 0 : dp[c] + 1);
            // Largest rectangle in a 2D histogram algorithm
            while (!s.empty() && dp[s.top()] > dp[c]) {
                int top = s.top(); s.pop();
                ans = max(ans, s.empty() ? dp[top] * c : dp[top] * (c - s.top() - 1));
            }
            s.push(c);
        }
        while (!s.empty()) {
            int top = s.top(); s.pop();
            ans = max(ans, s.empty() ? dp[top] * C : dp[top] * (C - s.top() - 1));
        }
    }
    cout << ans * 3 << ell;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TEST_CASES; cin >> TEST_CASES;
    for (int i = 1; i <= TEST_CASES; i++) solve();
}
