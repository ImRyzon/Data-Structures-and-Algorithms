#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5 + 1;
struct Node {int l, r; long long val, lazyVal, lazyInc; bool reset = false;} segTree[3 * MM];
int N, Q;

void pushUp(int idx) {
    segTree[idx].val = min(segTree[2 * idx].val, segTree[2 * idx + 1].val);
}
void pushDownVal(int idx) {
    int leftSon = 2 * idx, rightSon = 2 * idx + 1;
    segTree[leftSon].val = segTree[idx].lazyVal;
    segTree[leftSon].lazyVal = segTree[idx].lazyVal;
    segTree[rightSon].val = segTree[idx].lazyVal;
    segTree[rightSon].lazyVal = segTree[idx].lazyVal;
    segTree[idx].lazyVal = 0;
}

void pushDownInc(int idx) {
    int leftSon = 2 * idx, rightSon = 2 * idx + 1;
    if (segTree[idx].reset) {
        segTree[leftSon].lazyInc = segTree[idx].lazyInc;
        segTree[leftSon].reset = true;
        segTree[rightSon].lazyInc = segTree[idx].lazyInc;
        segTree[rightSon].reset = true;
        segTree[idx].reset = false;
    } else {
        segTree[leftSon].lazyInc += segTree[idx].lazyInc;
        segTree[rightSon].lazyInc += segTree[idx].lazyInc;
    }
    segTree[leftSon].val += segTree[idx].lazyInc;
    segTree[rightSon].val += segTree[idx].lazyInc;
    segTree[idx].lazyInc = 0;
}

void build(int l, int r, int idx) {
    segTree[idx].l = l;
    segTree[idx].r = r;
    if (l == r) {
        cin >> segTree[idx].val;
        segTree[idx].lazyVal = segTree[idx].lazyInc = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * idx);
    build(mid + 1, r, 2 * idx + 1);
    pushUp(idx);
}

void updateInc(int l, int r, long long delta, int idx) {
    if (segTree[idx].l == l && segTree[idx].r == r) {
        segTree[idx].val += delta;
        segTree[idx].lazyInc += delta;
        return;
    }
    if (segTree[idx].lazyVal) pushDownVal(idx);
    pushDownInc(idx);
    int mid = (segTree[idx].l + segTree[idx].r) / 2;
    if (r <= mid) updateInc(l, r, delta, 2 * idx);
    else if (l > mid) updateInc(l, r, delta, 2 * idx + 1);
    else {
        updateInc(l, mid, delta, 2 * idx);
        updateInc(mid + 1, r, delta, 2 * idx + 1);
    }
    pushUp(idx);
}

void updateVal(int l, int r, long long val, int idx) {
    if (segTree[idx].l == l && segTree[idx].r == r) {
        segTree[idx].val = val;
        segTree[idx].lazyVal = val;
        segTree[idx].lazyInc = 0;
        segTree[idx].reset = true;
        return;
    }
    if (segTree[idx].lazyVal) pushDownVal(idx);
    pushDownInc(idx);
    int mid = (segTree[idx].l + segTree[idx].r) / 2;
    if (r <= mid) updateVal(l, r, val, 2 * idx);
    else if (l > mid) updateVal(l, r, val, 2 * idx + 1);
    else {
        updateVal(l, mid, val, 2 * idx);
        updateVal(mid + 1, r, val, 2 * idx + 1);
    }
    pushUp(idx);
}

long long query(int l, int r, int idx) {
    if (segTree[idx].l == l && segTree[idx].r == r) return segTree[idx].val;
    if (segTree[idx].lazyVal) pushDownVal(idx);
    pushDownInc(idx);
    int mid = (segTree[idx].l + segTree[idx].r) / 2;
    if (r <= mid) return query(l, r, 2 * idx);
    if (l > mid) return query(l, r, 2 * idx + 1);
    return min(query(l, mid, 2 * idx), query(mid + 1, r, 2 * idx + 1));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> Q;
    build(1, N, 1);
    while (Q--) {
        // op --> type of operation
        int op, l, r, v;
        cin >> op;
        if (op == 1) { // Operation 1: Increment each value in the range [l, r] by v
            cin >> l >> r >> v;
            updateInc(l, r, v, 1);
        } else if (op == 2) { // Operation 2: Make the value in the range [l, r] equal to v
            cin >> l >> r >> v;
            updateVal(l, r, v, 1);
        } else { // Operation 3: Output the minimum value in the range [l, r]
            cin >> l >> r;
            cout << query(l, r, 1) << '\n';
        }
    }
}
