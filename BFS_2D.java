import java.io.*;
import java.util.*;

static boolean[][] vis = new boolean[9][9];
static int dis[][] = new int[9][9], endX, endY, ROW = 8, COL = 8;
static Integer vectorX[] = {-1, -2, -2, -1, 1, 2, 1, 2};
static Integer vectorY[] = {-2, -1, 1, 2, -2, -1, 2, 1};

public class bfs (int x, int y) {
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(x, y));
        vis[x][y] = true;
        while (!q.isEmpty()) {
            Pair cell = q.poll();
            int a = cell.first, b = cell.second;
            if (a == endX && b == endY) return;
            for (int i = 0; i < 8; i++) {
                int adjA = a + vectorX[i], adjB = b + vectorY[i];
                if (isValid(adjA, adjB)) {
                    q.add(new Pair(adjA, adjB));
                    vis[adjA][adjB] = true;
                    dis[adjA][adjB] = (dis[a][b] + 1);
                }
            }
        }
    }

static class Pair {
        int first, second;
        public Pair(int first, int second) {this.first = first; this.second = second;}
    }

static boolean isValid(int row, int col) {
        if (row < 1 || col < 1 || row > ROW || col > COL) return false;
        return !vis[row][col];
    }

