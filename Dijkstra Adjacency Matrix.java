import java.util.*;
import java.io.*;
public class DijkstraN2 {
    static void dijkstra (int dis[], int adj[][], boolean vis[], int n) {
        Arrays.fill(dis, Integer.MAX_VALUE);
        dis[1] = 0;
        for(int i = 1; i <= n; i++) {
            int min = Integer.MAX_VALUE;
            int u = -1;
            for(int j = 1; j <= n; j++){
                if(!vis[j]&&dis[j]<min) {
                    min = dis[j];
                    u = j;
                }
            }
            if(u==-1)break;
            vis[u]=true;
            for(int j = 1; j <= n; j++)
                if(adj[u][j]!=Integer.MAX_VALUE&&!vis[j])dis[j] = Math.min(dis[j], dis[u]+adj[u][j]);
        }
    }
}
