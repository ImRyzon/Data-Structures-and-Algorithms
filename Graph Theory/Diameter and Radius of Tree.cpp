#include <bits/stdc++.h>
using namespace std;

const int MM = 5e5 + 1;
vector<pair<int, int>> adj[MM];
int N, endA, endB, far = 0, dis[MM], radius = INT_MAX;

void dfs(int u, int parent, int d, int &endpoint) {
    if (d > far) {
        far = d;
        endpoint = u;
    }
    for (auto [v, w] : adj[u]) {
        if (v == parent) continue;
        dfs(v, u, d + w, endpoint);
    }
}

void dfs2(int u, int parent, int d) {
    dis[u] = max(dis[u], d);
    for (auto [v, w] : adj[u]) {
        if (v == parent) continue;
        dfs2(v, u, d + w);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N; // Get how many nodes are in the tree (numbered from 1 - N)
    for (int i = 1, u, v, w; i <= N-1; i++) {
        cin >> u >> v >> w; // Get edges and weights
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(1, -1, 0, endA);
    dfs(endA, -1, 0, endB);
    cout << far << '\n'; // Diameter of the given tree
    dfs2(endA, -1, 0);
    dfs2(endB, -1, 0);
    for (int i = 1; i <= N; i++) radius = min(radius, dis[i]);
    cout << radius << '\n'; // Radius of the given tree
    return 0;
}
