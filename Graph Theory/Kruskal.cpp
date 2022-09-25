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
int parent[MM], ranks[MM], N, M;
struct Edge {int u, v, w;} edges[MM];

bool comp(Edge a, Edge b) {
    return a.w < b.w;
}

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

bool Union(int x, int y) {
    int xRoot = Find(x), yRoot = Find(y);
    if (xRoot == yRoot) {
        return false;
    }
    if (ranks[xRoot] < ranks[yRoot]) {
        parent[xRoot] = yRoot;
    } else if (ranks[xRoot] > ranks[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[xRoot] = yRoot;
        ranks[yRoot]++;
    }
    return true;
}

void Kruskal() {
    sort(edges, edges + M + 1, comp);
    int sum = 0;
    vector<tuple<int, int, int>> MST;
    for (int i = 1; i <= M; i++) {
        if (Union(edges[i].u, edges[i].v)) {
            sum += edges[i].w;
            MST.emplace_back(edges[i].u, edges[i].v, edges[i].w);
        }
    }
    cout << "The total sum in the MST is: " << sum << "\n\n";
    cout << "The edges associated with the MST are: " << '\n';
    for (auto &e : MST) {
        cout << "{" << get<0>(e) << ", " << get<1>(e) << "} with a distance of " << get<2>(e) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    for (int i = 1, u, v, w; i <= M; i++) {
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    MakeSet();
    Kruskal();
}
