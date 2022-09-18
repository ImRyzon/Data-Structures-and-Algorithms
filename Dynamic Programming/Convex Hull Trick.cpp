#include <bits/stdc++.h>
using namespace std;

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
