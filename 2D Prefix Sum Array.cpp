#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define ull unsigned long long
#define vt vector
#define pii pair<int, int>
#define pll pair<long, long>
#define pb push_back
#define eb emplace_back
#define emp emplace
#define popf pop_front
#define popb pop_back
#define mp make_pair
#define umap unordered_map
#define fill(x, a) memset(x, a, sizeof(x))
#define all(c) (c).begin(), (c).end()

const int MM = 5002;
ll arr[MM][MM];

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k;
    for (int i = 0, a, b, c, d; i < k; i++) {
        cin >> a >> b >> c >> d;
        arr[a][b]++;
        arr[c+1][b]--;
        arr[a][d+1]--;
        arr[c+1][d+1]++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    cin >> q;
    for (int x = 0, a, b, c, d; x < q; x++) {
        cin >> a >> b >> c >> d;
        cout << arr[c][d] - arr[a-1][d] - arr[c][b-1] + arr[a-1][b-1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TEST_CASES = 1;
    for (int i = 1; i <= TEST_CASES; i++) solve();
}
