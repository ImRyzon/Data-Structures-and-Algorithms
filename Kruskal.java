import java.util.*;
import java.io.*;
public class Kruskal {
    static int p[];
    static int kruskal(int n, int m, Edge e[]) {
        int mst = 0, cnt = 0;
        for(int i =0; i < m; i++) {
            int u = e[i].u, v = e[i].v, w = e[i].w;
            if(cnt == n - 1) break;
            int fu = Find(u), fv = Find(v);
            if(fu != fv) { p[fu] = fv; cnt++; mst += w;}
        }
        return mst;
    }
    static int Find(int d) {
        if(d != p[d]) p[d] = Find(p[d]); return p[d];
    }
    static class Edge implements Comparable<Edge>{
        int u, v, w; public Edge(int u, int v, int w) {this.u = u; this.v = v; this.w = w;}
        public int compareTo(Edge x) { return Integer.compare(w,  x.w);}
    }
}
