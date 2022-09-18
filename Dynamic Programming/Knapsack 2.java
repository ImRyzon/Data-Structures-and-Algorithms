import java.io.*;
import java.util.*;
public class Main {
  static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
  
	public static void main(String[] args) throws IOException {
		int N = readInt(), W = readInt(), maxV = (int)1e5;
		long dp[] = new long[maxV+1];
		Arrays.fill(dp, (long)1e15);
		dp[0] = 0;
		for(int i=1; i<=N; i++) {
			int w = readInt(), v = readInt();
			for(int j=maxV; j>=v; j--)
				dp[j] = Math.min(dp[j], dp[j-v] + w);
		}
		for(int i=maxV; i>=0; i--)
			if(dp[i] <= W) { System.out.println(i); return; }
	}
  
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt () throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return in.readLine().trim();
	}
}
