#include <bits/stdc++.h>
using namespace std;

// Reference problem: https://dmoj.ca/problem/cco10p3

/**
* Query Types:
*
* N --> the value at index X is Y (new index)
* M --> the value at index X is modified to be Y
* Q --> Find the index of the X-th highest rated element
*/

const int MM = 1e6 + 1;
int BIT[MM], track[MM], idx[MM], N, len = 0;
struct Query {char op; int x, y;} q[MM]; // Store queries to be answered offline
vector<int> compress; // For coordinate compression

void update(int i, int val) {
    for (; i <= N; i += (i & -i)) {
        BIT[i] += val;
    }
}

int sum(int i) {
    int ans = 0;
    for (; i; i -= (i & -i)) {
        ans += BIT[i];
    }
    return ans;
}

int query(int k) {
    int low = 1, high = N;
    while (high > low) {
        int mid = (low + high) >> 1;
        if (k <= sum(mid)) high = mid;
        else low = mid + 1;
    }
    return low;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> q[i].op >> q[i].x;
        if (q[i].op == 'N' || q[i].op == 'M') {
            cin >> q[i].y;
            compress.push_back(q[i].y);
        }
    }
    sort(compress.begin(), compress.end());
    compress.resize(unique(compress.begin(), compress.end()) - compress.begin());
    for (int i = 1; i <= N; ++i) {
        if (q[i].op == 'Q') {
            cout << idx[query(len - q[i].x + 1)] << '\n'; // Instead of finding X-th highest, we can find (length - X + 1)th lowest
        } else if (q[i].op == 'N') {
            int val = lower_bound(compress.begin(), compress.end(), q[i].y) - compress.begin() + 1;
            track[q[i].x] = val;
            idx[val] = q[i].x;
            update(val, 1);
            ++len;
        } else {
            int val = lower_bound(compress.begin(), compress.end(), q[i].y) - compress.begin() + 1;
            update(track[q[i].x], -1);
            track[q[i].x] = val;
            idx[val] = q[i].x;
            update(val, 1);
        }
    }
}
