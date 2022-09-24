#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#define pb push_back
#define pf push_front
#define ef emplace_front
#define eb emplace_back
#define popf pop_front
#define popb pop_back
#define umap unordered_map
#define uset unordered_set
#define ell '\n'
#define all(x) x.begin(), x.end()
#define scan(x) do{while((x=getchar())<'0');for(x-='0';'0'<=(_=getchar());x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int MM = 1e6 + 1;
vector<int> adj[MM], order;
bool vis[MM];
int N, M, pos[MM];

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
    order.push_back(u);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 1, u, v; i <= M; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= N; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (int i = 0, j = N-1; i < N; i++) {
        pos[order[i]] = j;

        --j;
    }
    for (int i = 0; i < N; i++) {
        for (int u : adj[i]) {
            if (pos[i] > pos[u]) {
                cout << "A cycle exists" << '\n';
                cout << i << " " << u << '\n';
                return 0;
            }
        }
    }
    cout << "There is no cycle" << '\n';
}
