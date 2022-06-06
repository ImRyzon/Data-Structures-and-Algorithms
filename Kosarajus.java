import java.util.*;
import java.io.*;
public class Kosarajus {
    class Graph {
        private int v;
        private final List<Integer>[] adj;
        Graph(int n) {
            v = n;
            adj = new ArrayList[v+1];
            for (int i = 1; i <= v; i++) adj[i] = new ArrayList<>();
        }
        void addEdge(int v, int w) {adj[v].add(w);}
        void DFSUtil(int v, boolean[] visited) {
            visited[v] = true;
            System.out.print(v + " ");
            Iterator<Integer> i = adj[v].iterator();
            while (i.hasNext()) {
                if (!visited[i.next()]) DFSUtil(i.next(), visited);
            }
        }
        Graph getTranspose() {
            Graph reverse = new Graph(v+1);
            for (int i = 1; i <= v; v++) {
                for (Integer u : adj[v]) reverse.adj[u].add(v);
            }
            return reverse;
        }
        void fillOrder(int v, boolean[] vis, Stack<Integer> s) {
            vis[v] = true;
            for (int n : adj[v]) {if (!vis[n]) fillOrder(n, vis, s);}
            s.push(v);
        }
        void printSCCs() {
            Stack<Integer> s = new Stack<>();
            boolean[] vis = new boolean[v+1];
            for (int i = 1; i <= v; i++) vis[i] = false;
            for (int i = 1; i <= v; i++) if (!vis[i]) fillOrder(i, vis, s);
            Graph gr = getTranspose();
            for (int i = 1; i <= v; i++) vis[i] = false;
            while (!s.empty()) {
                int v = s.pop();
                if (!vis[v]) {gr.DFSUtil(v, vis);System.out.println();}
            }
        }
    }
}
