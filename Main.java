import java.io.*;
import java.util.*;
public class Main {
    static FastIO r = new FastIO();
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    public static void main(String[] args) throws Exception {
        int n = r.readInt(), m = r.readInt();
        List<edge> adj[] = new ArrayList[n+1], rev[] = new ArrayList[n+1];
        for(int i=1; i<=n; i++) {
            adj[i] = new ArrayList<>(); rev[i] = new ArrayList<>();
        }
        for(int i=1; i<=m; i++) {
            int u = r.readInt(), v = r.readInt(), w = r.readInt();
            adj[u].add(new edge(v, w)); rev[v].add(new edge(u, w));
            adj[v].add(new edge(u, w)); rev[u].add(new edge(v, w));
        }
        int dis1[] = new int[n+1], dis2[] = new int[n+1];
        spfa(1, n, adj, dis1); spfa(n, n, rev, dis2);
        int ans = dis1[n], inf = (int)1e9;
        if(ans == inf) { System.out.println(-1); return; }
        int second = inf;
        for(int u=1; u<=n; u++) {
            for(edge e : adj[u]) {
                if(dis1[u] != inf && dis2[e.v] != inf) {
                    int val = dis1[u] + e.w + dis2[e.v];
                    if(val > ans && val < second) second = val;
                }
            }
        }
        pr.println(second == inf? -1 : second); pr.close();
    }
    static void spfa(int start, int n, List<edge> adj[], int dis[]) {
        Arrays.fill(dis, (int)1e9); boolean inq[] = new boolean[n+1];
        Queue<Integer> q = new LinkedList<>();
        dis[start] = 0; q.add(start); inq[start]=true;
        while(!q.isEmpty()) {
            int u = q.poll(); inq[u] = false;
            for(edge e : adj[u]) {
                if(dis[e.v] > dis[u] + e.w) {
                    dis[e.v] = dis[u] + e.w;
                    if(!inq[e.v]) { q.add(e.v); inq[e.v]=true;}
                }
            }
        }
    }
    static class edge {
        int v, w;
        edge(int v0, int w0) { v = v0; w = w0; }
    }

    static class FastIO extends PrintWriter {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar, numChars;
        public FastIO() {this(System.in, System.out);}
        public FastIO(InputStream i, OutputStream o) {super(o);stream = i;}
        public FastIO(String i, String o) throws IOException {
            super(new FileWriter(o)); stream = new FileInputStream(i);
        }
        private int readByte() {
            if (numChars == -1) {throw new InputMismatchException();}
            if (curChar >= numChars) {
                curChar = 0;
                try {numChars = stream.read(buf);
                }catch(Exception e){throw new InputMismatchException();}
                if (numChars == -1) {return -1;}
            }
            return buf[curChar++];
        }
        public String next() {
            int c; do {c = readByte();} while (c <= ' ');
            StringBuilder res = new StringBuilder();
            do {res.appendCodePoint(c);c = readByte();} while (c > ' ');
            return res.toString();
        }
        public String readLine() {
            int c; do {c = readByte();} while (isEndLine(c));
            StringBuilder res = new StringBuilder();
            do {res.appendCodePoint(c);c = readByte();} while (c >= ' ');
            return res.toString();
        }
        public int readInt() {
            int c, sgn = 1, res = 0;
            do {c = readByte();} while (c <= ' ');
            if (c == '-') {sgn = -1;c = readByte();}
            do {
                if (c < '0' || c > '9') {throw new InputMismatchException();}
                res = 10 * res + c - '0';c = readByte();
            } while (c > ' ');
            return res * sgn;
        }
        public double readDouble() {return Double.parseDouble(next());}
        public long readLong() {return Long.parseLong(next());}
        boolean isEndLine(int c) {return c == '\n' || c == '\r' || c == -1;}
    }
}