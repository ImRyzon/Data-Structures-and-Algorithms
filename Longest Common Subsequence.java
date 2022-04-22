import java.io.*;
import java.util.*;
public class Main {
    static FastIO r = new FastIO();
    static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    public static void main(String[] args) throws Exception {
        String a = r.readLine(), b = r.readLine();
        lcs(a, b, a.length(), b.length());
    }

    static void lcs (String X, String Y, int m, int n) {
        int[][] t = new int[m+1][n+1];
        for (int i=0; i<=m; i++) {
            for (int j=0; j<=n; j++) {
                if (i == 0 || j == 0) t[i][j] = 0;
                else if (X.charAt(i-1) == Y.charAt(j-1)) t[i][j] = t[i-1][j-1] + 1;
                else t[i][j] = Math.max(t[i-1][j], t[i][j-1]);
            }
        }
        int index = t[m][n], temp = index, i = m, j = n;
        char[] lcs = new char[index+1]; lcs[index] = '\u3164';
        while (i > 0 && j > 0)  {
            if (X.charAt(i-1) == Y.charAt(j-1)) {lcs[index-1] = X.charAt(i-1);i--;j--;index--;}
            else if (t[i-1][j] > t[i][j-1]) i--; else j--;
        }
        for(int k=0;k<temp;k++) pr.print(lcs[k]);
        pr.println(); pr.close();
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
