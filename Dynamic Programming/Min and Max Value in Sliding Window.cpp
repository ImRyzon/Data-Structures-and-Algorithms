#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define popf pop_front
#define popb pop_back
#define scan(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int N, M, C;
    scan(N); scan(M); scan(C);
    deque<pair<int, int>> mx, mi;
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
