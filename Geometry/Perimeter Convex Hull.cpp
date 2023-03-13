#include <bits/stdc++.h>
using namespace std;

int N, T;
vector<pair<long double, long double>> p, stk;
pair<long double, long double> o(1e18, 1e18);

long double cross(auto o, auto a, auto b) {
    return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first);
}

long double distance(pair<long double, long double> a, pair<long double, long double> b) {
    return sqrt((b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second));
}

bool comp(pair<long double, long double> a, pair<long double, long double> b) {
    long double val = cross(o, a, b);
    return val > 0 || val == 0 && a < b;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> T;
    while (T--) {
        cin >> N;
        p.clear();
        stk.clear();
        o = {1e18, 1e18};
        p.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> p[i].first >> p[i].second;
            o = min(o, p[i]);
        }
        sort(p.begin(), p.end(), comp);
        for (int i = 0; i < N; ++i) {
            while (stk.size() > 1 && cross(stk[stk.size()-2], stk.back(), p[i]) <= 0) stk.pop_back();
            stk.push_back(p[i]);
        }
        long double ans = 0.0f;
        for (int i = 0; i < stk.size() - 1; ++i) ans += distance(stk[i], stk[i+1]);
        ans += distance(stk[0], stk[stk.size() - 1]);
        printf("%.2Lf\n", ans);
    }
}
