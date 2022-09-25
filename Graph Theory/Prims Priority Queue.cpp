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
vector<pair<int, int>> adj[MM];
int dis[MM], N, M;
bool vis[MM];

void Prim() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= N; i++) {
        vis[i] = false;
        dis[i] = INT_MAX;
    }
    dis[1] = 0;
    pq.push({dis[1], 1});
    int sum = 0;
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        int u = cur.second;
        if (!vis[u]) {
            vis[u] = true;
            sum += cur.first;
            for (pair<int, int> e : adj[u]) {
                int v = e.first, w = e.second;
                if (!vis[v] && w < dis[v]) {
                    dis[v]  = w;
                    pq.push({dis[v], v});
                }
            }
        }
    }
    cout << "The sum of the MST is: " << sum << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 1, u, v, w; i <= M; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    Prim();
}
