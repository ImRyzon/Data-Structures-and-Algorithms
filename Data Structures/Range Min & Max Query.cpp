#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int MM = 5e4 + 1;
const int LOG = 17;
int mx[MM][LOG], mi[MM][LOG];

int queryMin(int L, int R) {
    int k = floor(log2(R - L + 1));
    return min(mi[L][k], mi[R-(1<<k)+1][k]);
}

int queryMax(int L, int R) {
    int k = floor(log2(R - L + 1));
    return max(mx[L][k], mx[R-(1<<k)+1][k]);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int N, Q;
    cin >> N >> Q;

    // Scan the array
    for (int i = 0; i < N; i++) {
        cin >> mx[i][0];
        mi[i][0] = mx[i][0];
    }

    // Pre-process
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i + (1 << k) - 1 < N; i++) {
            mi[i][k] = min(mi[i][k-1], mi[i + (1 << (k-1))][k-1]);
            mx[i][k] = max(mx[i][k-1], mx[i + (1 << (k-1))][k-1]);
        }
    }

    // Query
    for (int i = 0, l, r; i < Q; i++) {
        cin >> l >> r;
        --l; --r;
        printf("%d\n", queryMax(l, r) - queryMin(l, r));
    }
}
