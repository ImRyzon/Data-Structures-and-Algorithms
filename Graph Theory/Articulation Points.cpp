#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast","unroll-loops","omit-frame-pointer","inline")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#define scan(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MM = 1e5 + 1;
vector<int> adj[MM], ans;
bool vis[MM];
int initial[MM], minSub[MM], N, M, cnt = 0;

void dfs(int u, int parent) {
    int children = 0;
    vis[u] = true;
    initial[u] = minSub[u] = ++cnt;
    for (int v : adj[u]) {
        if (!vis[v]) {
            ++children;
            dfs(v, u);
            minSub[u] = min(minSub[u], minSub[v]);
            if (parent != -1 && minSub[v] >= initial[u]) ans.push_back(u);
        } else if (v != parent) {
            minSub[u] = min(minSub[u], initial[v]);
        }
    }
    if (parent == -1 && children > 1) ans.push_back(u);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 1, u, v; i <= M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << '\n';
    for (int u : ans) cout << u << '\n';
}
