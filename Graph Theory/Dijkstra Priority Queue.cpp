const int MM = 1e6;

void dijkstra(int start, int dis[MM], bool vis[MM];) {
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
}
