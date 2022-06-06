import java.io.*;
import java.util.*;
public class TopologicalSort {
    static class Graph {
        private final int v;
        private final ArrayList<Integer>[] adj;
        Graph(int n) {
            v = n;
            adj = new ArrayList[v+1];
            for (int i = 1; i <= v; i++) adj[i] = new ArrayList<>();
        }
        void addEdge(int v, int w) {adj[v].add(w);}
        void topoSort(int v, boolean[] vis, Stack<Integer> s) {
            vis[v] = true;
            for (Integer u : adj[v]) if (!vis[u]) topoSort(u, vis, s);
            s.push(v);
        }
        void topoSort() {
            Stack<Integer> s = new Stack<>();
            boolean[] vis = new boolean[v+1];
            for (int i = 1; i <= v; i++) if (!vis[i]) topoSort(i, vis, s);
            while (!s.empty()) System.out.print((s.pop()) + " ");
            System.out.println();
        }
    }
}
