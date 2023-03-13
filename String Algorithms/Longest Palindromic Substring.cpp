#include <bits/stdc++.h>
using namespace std;

int N, st = 0, len = 0;
string s;

bool palindrome(int l, int r){
    if(r >= N) return 0;
    while (l <= r){
        if (s[l] != s[r]) return 0;
        l++;
        r--;
    }
    return 1;
}

bool works(int mid){
    for (int i=0; i<=N;i++){
        if (i + mid - 1 >= N) break;
        if (palindrome(i, i+mid-1)){
            len = mid; st = i;
            return true;
        }
    }
    return false;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin >> N >> s;
    int low = 0, high = s.size();
    while (high >= low) {
        int mid = (low + high) >> 1;
        if (works(mid) || works(mid + 1)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    string ans = s.substr(st, len);
    cout << ans << '\n' << ans.size() << '\n';
}
