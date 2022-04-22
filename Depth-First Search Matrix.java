import java.util.*;
import java.io.*;
public class DFS {
    static boolean visited[];
    static boolean adj[][];
    static void dfs (int u, int m) {
        visited[u] = true;
        for (int j = 1; j <= m; j++) {
            if (adj[u][j] && !visited[j]) {
                dfs(j, m);
            }
        }

    }
}
