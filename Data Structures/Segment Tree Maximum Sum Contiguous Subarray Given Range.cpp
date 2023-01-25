#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5 + 1;
struct Node {int l, r;  long long left, right, tot, val;} seg[3 * MM];
int N, Q;

// S: change the value at index X to be Y
// Q: print the maximum contiguous sum in the range [X, Y]

void pushUp(int idx) {
    seg[idx].left = max(seg[2 * idx].left, seg[2 * idx].tot + seg[2 * idx + 1].left);
    seg[idx].right = max(seg[2 * idx + 1].right, seg[2 * idx + 1].tot + seg[2 * idx].right);
    seg[idx].tot = seg[2 * idx].tot + seg[2 * idx + 1].tot;
    seg[idx].val = max(seg[idx].left,
                       max(seg[idx].right,
                           max(seg[2 * idx].val,
                               max(seg[2 * idx + 1].val, seg[2 * idx].right + seg[2 * idx + 1].left))));
}

void build(int l, int r, int idx) {
    seg[idx].l = l;
    seg[idx].r = r;
    if (l == r) {
        cin >> seg[idx].val;
        seg[idx].left = seg[idx].right = seg[idx].tot = seg[idx].val;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, 2 * idx);
    build(mid + 1, r, 2 * idx + 1);
    pushUp(idx);
}

void update(int pos, int val, int idx) {
    if (seg[idx].l == seg[idx].r) {
        seg[idx].val = seg[idx].left = seg[idx].right = seg[idx].tot = val;
        return;
    }
    int mid = (seg[idx].l + seg[idx].r) >> 1;
    if (pos <= mid) update(pos, val, 2 * idx);
    else update(pos, val, 2 * idx + 1);
    pushUp(idx);
}

Node query(int l, int r, int idx) {
    if (seg[idx].l == l && seg[idx].r == r) return seg[idx];
    int mid = (seg[idx].l + seg[idx].r) >> 1;
    if (r <= mid) return query(l, r, 2 * idx);
    if (l > mid) return query(l, r, 2 * idx + 1);
    Node a = query(l, mid, 2 * idx), b = query(mid + 1, r, 2 * idx + 1), cur;
    cur.left = max(a.left, a.tot + b.left);
    cur.right = max(b.right, b.tot + a.right);
    cur.tot = a.tot + b.tot;
    cur.val = max(cur.left, max(cur.right, max(a.val, max(b.val, a.right + b.left))));
    return cur;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> Q;
    build(1, N, 1);
    while (Q--) {
        char op;
        int x, y;
        cin >> op >> x >> y;
        if (op == 'S') update(x, y, 1);
        else cout << query(x, y, 1).val << '\n';
    }
}
