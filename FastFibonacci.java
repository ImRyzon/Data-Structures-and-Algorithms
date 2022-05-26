import java.io.*;
import java.util.*;

public static void main(String[] args) throws Exception {
        long n = r.readLong(), f[] = new long[2];
        FastDoubling(n, f);
        System.out.println(f[0]);
    }


// Calculate the nth Fibonacci Number using a O(log (n)) algorithm
static void FastDoubling(long n, long f[]) {
        long a, b, c, d, MOD = 1000000007;
        if (n == 0) {f[0] = 0;f[1] = 1;return;}
        FastDoubling((n / 2), f);
        a = f[0];b = f[1];c = 2 * b - a;
        if (c < 0) c += MOD;
        c = (a * c) % MOD; d = (a * a + b * b) % MOD;
        if (n % 2 == 0) {f[0] = c;f[1] = d;}
        else {f[0] = d;f[1] = c + d;}
    }
