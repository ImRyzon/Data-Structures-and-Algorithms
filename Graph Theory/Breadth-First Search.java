import java.util.*;
import java.io.*;
public class BFS {
    static boolean vis[];
    static List<Integer> adj[];
    static void bfs(int st) {
        LinkedList<Integer> q = new LinkedList<Integer>();
        vis[st] = true;
        q.add(st);
        while(!q.isEmpty()) {
            int u = q.poll();
            for(int v : adj[u]) {
                if(!vis[v]) {
                    q.add(v);
                    vis[v] = true;
                }
            }
        }
    }
}
