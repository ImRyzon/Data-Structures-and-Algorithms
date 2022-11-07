#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5 + 1;
int parent[MM], ranks[MM], N, Q;

void MakeSet() {
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
}

int Find(int x) {
    if (parent[x] != x) {
        parent[x] = Find(parent[x]);
    }
    return parent[x];
}

void Union(int x, int y) {
    int xRoot = Find(x), yRoot = Find(y);
    if (xRoot == yRoot) return;
    if (ranks[xRoot] < ranks[yRoot]) {
        parent[xRoot] = yRoot;
    } else if (ranks[xRoot] > ranks[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[xRoot] = yRoot;
        ranks[yRoot]++;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> Q;
    MakeSet();
    // A: Union u with v
    // Q: query if u and v are in the same disjoint set
    for (int i = 1; i <= Q; i++) {
        char op;
        int u, v;
        cin >> op >> u >> v;
        if (op == 'A') Union(u, v);
        else cout << (Find(u) == Find(v) ? "Y\n" : "N\n");
    }
}
