import java.util.*;
import java.io.*;
public class DFSAdjList {
    static boolean vis[];
    static List<Integer> adj[];
    static void dfs(int u) {
        vis[u] = true;
        for(int v: adj[u]) {
            if(!vis[v]) {
                dfs(v);
            }
        }
    }
}
