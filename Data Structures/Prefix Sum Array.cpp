#include <bits/stdc++.h>
using namespace std;

void getPrefixSum(int arr[], int n, int psa[]) {
    psa[0] = arr[0];
    for (int i = 1; i < n; i++) {
        psa[i] = psa[i-1] + arr[i];
    }
} 

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int arr[] = {1, 4, -3, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int psa[n];
    getPrefixSum(arr, n, psa);
}
