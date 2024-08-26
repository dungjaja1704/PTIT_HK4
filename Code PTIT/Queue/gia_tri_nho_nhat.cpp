#include <bits/stdc++.h>
using namespace std;
void solve() {
    priority_queue<int> pq;
    int k; cin >> k;
    string s; cin >> s;
    int d[256] = {0};
    for(char x : s) {
        d[x]++;
    }
    for(int i = 0; i < 256; i++) {
        if(d[i]) pq.push(d[i]);
    }
    while(k-- && !pq.empty()) {
        int u = pq.top(); pq.pop();
        if(u-1>0){
            pq.push(u-1);
        }
    }
    long long res = 0;
    while(!pq.empty()) {
        int u = pq.top(); pq.pop();
        res += (long long)u*u;
    }
    cout << res << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}