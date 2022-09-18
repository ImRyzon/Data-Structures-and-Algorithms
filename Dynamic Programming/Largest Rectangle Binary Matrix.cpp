#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
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
    cout << ans << '\n';
}
