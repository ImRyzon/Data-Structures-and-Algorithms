#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#define scan(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MM = 6003, LOG = 18;
vector<pair<int, int>> adj[MM];
vector<int> euler;
pair<int, int> st[2*MM][LOG];
int N, Q, depth[MM], in[MM];
long long dis[MM];

void dfs(int u, int parent) {
    in[u] = euler.size();
    euler.push_back(u);
    for (auto [v, w] : adj[u]) {
        if (v == parent) continue;
        depth[v] = depth[u] + 1;
        dis[v] = dis[u] + w;
        dfs(v, u);
        euler.push_back(u);
    }
}

int lca(int u, int v) {
    int l = in[u], r = in[v];
    if (l > r) swap(l, r);
    int k = log2(r - l + 1);
    return min(st[l][k], st[r - (1 << k) + 1][k]).second;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N;
    for (int i = 1, u, v, w; i <= N-1; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(0, -1);
    for (int i = 0; i < euler.size(); i++) st[i][0] = {depth[euler[i]], euler[i]};
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i + (1 << k) - 1 < euler.size(); i++) {
            st[i][k] = min(st[i][k-1], st[i + (1 << (k - 1))][k-1]);
        }
    }
    cin >> Q;
    for (int i = 1, u, v; i <= Q; i++) {
        cin >> u >> v;
        cout << "The LCA of the two nodes is: " << lca(u, v) << '\n';
        cout << "This distance betwwen the two nodes is: " << dis[u] + dis[v] - 2 * dis[lca(u, v)] << '\n';
    }
}
