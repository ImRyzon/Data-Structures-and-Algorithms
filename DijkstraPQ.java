import java.util.*;
import java.io.*;
public class DijkstraPQ {
    static void dijkstra (int start, List<Edge> adj[], int dis[]) {
        Arrays.fill(dis, Integer.MAX_VALUE); dis[start] = 0;
        PriorityQueue<Edge> q = new PriorityQueue<>();
        q.add(new Edge(start, dis[start]));
        while(!q.isEmpty()) {
            int u = q.peek().v; long d = q.peek().w; q.poll();
            if(d > dis[u]) continue;
            for(Edge e : adj[u]) {
                if(dis[e.v] > dis[u] + e.w) {
                    dis[e.v] = dis[u] + e.w; q.add(new Edge(e.v, dis[e.v]));
                }
            }
        }
    }

    static class Edge implements Comparable <Edge> {
        int v, w;
        public Edge(int v, int w) {this.v = v; this.w = w;}
        public int compareTo(Edge e) {return w - e.w;}
    }
}
