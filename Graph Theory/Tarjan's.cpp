#include <bits/stdc++.h>
using namespace std;

const int MM = 1e3 + 1;
vector<int> adj[MM];
int in[MM], low[MM], arr[MM], track[MM], group = 1, cur = 1, N, M, Q;
bool member[MM];
stack<int> s;

void dfs(int u) {
    in[u] = low[u] = ++cur;
    s.push(u);
    member[u] = true;
    for (int v : adj[u]) {
        if (in[v] == -1) dfs(v);
        else if (member[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == in[u]) {
        while (!s.empty()) {
            track[s.top()] = group;
            member[s.top()] = false;
            s.pop();
        }
        ++group;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
        in[i] = -1;
        low[i] = -1;
    }
    for (int i = 1, u, v; i <= M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= N; i++) {
        if (in[i] == -1) {
            dfs(i);
        }
    }
    for (int i = 1, u, v; i <= Q; i++) {
        cin >> u >> v;
        if (track[u] == track[v]) cout << u << " and " << v << " are in the same strongly connected component.\n";
        else cout << u << " and " << v << " are in different strongly connected components.\n";
    }
}
