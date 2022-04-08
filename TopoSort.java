import java.util.*;
import java.io.*;
public class TopoSort {
    static List<Integer> adj[];
    static int count[], n, m, output;

    static void topoSort(int u) {
        PriorityQueue<Integer> q = new PriorityQueue<>();
        for (int i = 1; i <= n; i++) {
            if (count[i] == 0) {
                q.add(i);
                output++;
            }
        }
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int nxt : adj[cur]) {
                count[nxt]--;
                if (count[nxt] == 0) {
                    q.add(nxt);
                    output++;
                }
            }
        }
    }
}
