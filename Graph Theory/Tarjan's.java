import java.util.*;
import java.io.*;
public class Tarjans {
    static class Graph {
        private final int n;
        private int time;
        private final LinkedList<Integer>[] adj;
        @SuppressWarnings("unchecked")
        Graph(int v) {
            n = v;
            adj = new LinkedList[v+1];
            for (int i = 1; i <= v; i++) adj[i] = new LinkedList<>();
            time = 0;
        }
        void addEdge(int v, int w) {adj[v].add(w);}
        void dfs(int u, int low[], int disc[], boolean[] stackMember, Stack<Integer> st) {
            disc[u] = time;
            low[u] = time;
            time++;
            stackMember[u] = true;
            st.push(u);
            for (Integer integer : adj[u]) {
                if (disc[integer] == -1) {
                    dfs(integer, low, disc, stackMember, st);
                    low[u] = Math.min(low[u], low[integer]);
                } else if (stackMember[integer]) {
                    low[u] = Math.min(low[u], disc[integer]);
                }
            }
            int w = -1;
            if (low[u] == disc[u]) {
                while (w != u) {
                    w = st.pop();
                    System.out.print(w + " ");
                    stackMember[w] = false;
                }
                System.out.println();
            }
        }
        void stronglyConnectedComponents() {
            int[] disc = new int[n+1], low = new int[n+1];
            for (int i = 1; i <= n; i++) {
                disc[i] = -1;
                low[i] = -1;
            }
            boolean[] stackMember = new boolean[n+1];
            Stack<Integer> st = new Stack<>();
            for (int i = 1; i <= n; i++) {
                if (disc[i] == -1) dfs(i, low, disc, stackMember, st);
            }
        }
    }
}
