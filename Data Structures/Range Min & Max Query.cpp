#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#define scan(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MM = 5e4 + 1, LOG = 18;
int mx[MM][LOG], mi[MM][LOG], N, Q;
int queryMin(int l, int r) {
    int k = log2(r - l + 1);
    return min(mi[l][k], mi[r - (1 << k) + 1][k]);
}
int queryMax(int l, int r) {
    int k = log2(r - l + 1);
    return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> mx[i][0];
        mi[i][0] = mx[i][0];
    }
    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i + (1 << (k - 1)) <= N; i++) {
            mx[i][k] = max(mx[i][k-1], mx[i + (1 << (k - 1))][k-1]);
            mi[i][k] = min(mi[i][k-1], mi[i + (1 << (k - 1))][k-1]);
        }
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << "Max value in that range is: " << queryMax(l, r) << "\n";
        cout << "Min value in that ranger is: " << queryMin(l, r) << '\n';
    }
}
