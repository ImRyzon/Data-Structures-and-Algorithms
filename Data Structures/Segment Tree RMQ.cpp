#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5 + 2;
struct Node {int l, r, val;} tree[3 * MM];
int N, M;
char op;

void pushUp(int idx) {
    tree[idx].val = min(tree[2 * idx].val, tree[2 * idx + 1].val);
}

void build(int l, int r, int idx) {
    tree[idx].l = l;
    tree[idx].r = r;
    if (l == r) {
        cin >> tree[idx].val;
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * idx); 
    build(mid + 1, r, 2 * idx + 1);
    pushUp(idx);
}

void update(int pos, int val, int idx) {
    if (tree[idx].l == tree[idx].r) {
        tree[idx].val = val;
        return;
    }
    int mid = (tree[idx].l + tree[idx].r) / 2;
    pos <= mid ? update(pos, val, 2 * idx) : update(pos, val, 2 * idx + 1);
    pushUp(idx);
}

int queryMin(int l, int r, int idx) {
    if (tree[idx].l == l && tree[idx].r == r) return tree[idx].val;
    int mid = (tree[idx].l + tree[idx].r) / 2;
    if (r <= mid) return queryMin(l, r, 2 * idx);
    if (l > mid) return queryMin(l, r, 2 * idx + 1);
    return min(queryMin(l, mid, 2 * idx), queryMin(mid + 1, r, 2 * idx + 1));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> M;
    build(0, N - 1, 1);
    for (int i = 1, x, y; i <= M; i++) {
        cin >> op >> x >> y;
        // M: update element at index x to be y
        // Q: range minimum query from [x, y]
        if (op == 'M') update(x, y, 1);
        if (op == 'Q') cout << queryMin(x, y, 1) << "\n";
    }
}
