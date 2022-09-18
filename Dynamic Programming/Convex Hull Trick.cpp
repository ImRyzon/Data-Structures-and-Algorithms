#include <bits/stdc++.h>
using namespace std;

#define int long long
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

struct ConvexHullTrick {
    struct Line {
        int slope, yIntercept;
        Line(int slope, int yIntercept) : slope(slope), yIntercept(yIntercept) {}
        int val(int x) {return slope * x + yIntercept;}
        int intersect(Line y) {return (y.yIntercept - yIntercept + slope - y.slope - 1) / (slope - y.slope);}
    };
    deque<pair<Line, int>> dq;
    void insert(int slope, int yIntercept) {
        Line newLine(slope, yIntercept);
        while (dq.size() > 1 && dq.back().second >= dq.back().first.intersect(newLine)) dq.pop_back();
        if (dq.empty()) {dq.emplace_back(newLine, 0); return;}
        dq.emplace_back(newLine, dq.back().first.intersect(newLine));
    }
    int query(int x) {
        while (dq.size() > 1) {if (dq[1].second <= x) dq.pop_front(); else break;}
        return dq[0].first.val(x);
    }
};
