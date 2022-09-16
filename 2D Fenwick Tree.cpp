#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
const int MM = 1025;
int BIT[MM][MM];
void update(int r, int c, int x) {
    for (int i = r; i < MM; i += i & -i) {
        for (int j = c; j < MM; j += j & -j) {
            BIT[i][j] += x;
        }
    }
}
int query(int r, int c) {
    int sum = 0;
    for (int i = r; i; i -= i & -i) {
        for (int j = c; j; j -= j & -j) {
            sum += BIT[i][j];
        }
    }
    return sum;
}
