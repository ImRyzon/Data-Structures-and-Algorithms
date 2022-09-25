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

void dijkstra(int start) {
    for (int i = 0; i < MM; i++) {
        vis[i] = false;
        dis[i] = 0x3F3F3F3F;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[start] = 0;
    pq.push({dis[start], start});
    while (!pq.empty()) {
        pair<int, int> x = pq.top();
        pq.pop();
        if (!vis[x.second]) {
            vis[x.second] = true;
            for (auto &e : adj[x.second]) {
                int v = e.first, w = e.second;
                if (!vis[v] && dis[x.second] + w < dis[v]) {
                    dis[v] = dis[x.second] + w;
                    pq.push({dis[v], v});
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (dis[i] == 0x3F3F3F3F) {
            cout << "There is no path from 1 --> " << i << '\n';
            continue;
        }
        cout << "The shortest distance from 1 --> " << i << " is: " << dis[i] << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 1, u, v, w; i <= M; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    dijkstra(1);
}
