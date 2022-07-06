import java.io.*;
import java.util.*;
public class Main {
    static final int MAX = 10000001;
    static void sieve() {
        boolean[] prime = new boolean[MAX];
        for (int i = 2; i < MAX; i++) {
            if (!prime[i]) {
                for (int j = i; j < MAX; j += i) {
                    prime[j] = true;
                }
            }
        }
    }
}
