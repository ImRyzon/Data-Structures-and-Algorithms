#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
struct E { int x, yl, yh, val;};
int N, M, bit[3*MM], ans;  vector<E> event; vector<int> rk;
bool cmp(E& a, E& b){ return a.x < b.x || a.x==b.x && a.val > b.val; } //sort by x, same x (left, point, right)
void upd(int pos, int val) {
    for(int i=pos+1; i<3*MM; i+=i&-i) bit[i] += val;
}
int qry(int pos){
    int ret = 0;
    for(int i=pos+1; i>0; i-=i&-i) ret += bit[i];
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1, a, b, c, d; i<=N; i++) {
        cin >> a >> b >> c >> d;  rk.push_back(b); rk.push_back(d);
        event.push_back({a, b, d, 1}); event.push_back({c, b, d, -1});
    }
    for(int i=1, a, b; i<=M; i++){
        cin >> a >> b;  rk.push_back(b);
        event.push_back({a, b, b, 0});
    }
    sort(rk.begin(), rk.end()); rk.resize(unique(rk.begin(), rk.end()) - rk.begin());
    sort(event.begin(), event.end(), cmp);
    for(auto [x, yl, yh, val] : event){
        if(val != 0) {
            yl = lower_bound(rk.begin(), rk.end(), yl) - rk.begin(); yh = lower_bound(rk.begin(), rk.end(), yh) - rk.begin();
            upd(yl, val);  upd(yh+1, -val);
        }else {
            yl = lower_bound(rk.begin(), rk.end(), yl) - rk.begin();
            ans += (qry(yl) > 0);
        }
    }
    cout << ans << endl;
}
