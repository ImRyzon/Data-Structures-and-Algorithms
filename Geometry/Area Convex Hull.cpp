#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<double, double>> p, stk;
pair<double, double> o(1e9, 1e9);

double cross(auto o, auto a, auto b) {
    return (a.first - o.first) * (b.second - o.second) - (a.second - o.second) * (b.first - o.first);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N;
    p.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i].first >> p[i].second;
        o = min(o, p[i]);
    }
    sort(p.begin(), p.end(), [&](pair<double, double> a, pair<double, double> b) {
        double val = cross(o, a, b);
        return val > 0 || val == 0 && a.first < b.first;
    });
    for (int i = 0; i < N; ++i) {
        while (stk.size() > 1 && cross(stk[stk.size()-2], stk.back(), p[i]) <= 0) stk.pop_back();
        stk.push_back(p[i]);
    }
    double area = 0.0f;
    for (int i = 1; i < stk.size() - 1; ++i) area += cross(stk[0], stk[i], stk[i+1]) * 0.5f;
    printf("%d\n", (int)(area / 50));
}
