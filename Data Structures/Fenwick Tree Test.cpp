#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast,unroll-loops")
#pragma GCC target ("avx2")
#define scan(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MM = 1e5 + 1;
long long fenwick[MM], track[MM];
void update(int i, int val, long long (&tree)[MM]) {
    for(; i < MM; i += i & -i) {
        tree[i] += val;
    }
}
long long query(int i, long long (&tree)[MM]) {
    long long total = 0;
    for (; i; i -= i & -i) {
        total += tree[i];
    }
    return total;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int N, M;
    scan(N); scan(M);
    for (int i = 1, a; i <= N; i++) {
        scan(a);
        update(i, a, fenwick);
        update(a, 1, track);
    }
    for (int i = 1, a, b; i <= M; i++) {
        char op = getchar();
        if (op == 'C') {
            scan(a); scan(b);
            int val = query(a, fenwick) - query(a-1, fenwick);
            update(a, b - val, fenwick);
            update(val, -1, track);
            update(b, 1, track);
        } else if (op == 'S') {
            scan(a); scan(b);
            printf("%lld\n", query(b, fenwick) - query(a-1, fenwick));
        } else {
            scan(a);
            printf("%lld\n", query(a, track));
        }
    }
}
