import java.util.*;
import java.io.*;
public class SPFA {
    static void spfa(int start, int n, List<edge> adj[], int dis[]) {
        Arrays.fill(dis, (int)1e9); boolean inq[] = new boolean[n+1];
        Queue<Integer> q = new LinkedList<>();
        dis[start] = 0; q.add(start); inq[start]=true;
        while(!q.isEmpty()) {
            int u = q.poll(); inq[u] = false;
            for(edge e : adj[u]) {
                if(dis[e.v] > dis[u] + e.w) {
                    dis[e.v] = dis[u] + e.w;
                    if(!inq[e.v]) { q.add(e.v); inq[e.v]=true;}
                }
            }
        }
    }
    static class edge {
        int v, w;
        edge(int v0, int w0) { v = v0; w = w0; }
    }
}
