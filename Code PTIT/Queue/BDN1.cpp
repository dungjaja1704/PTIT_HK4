#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> v;
void xuly() {
    queue<ll> q;
    q.push(1);
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        v.push_back(u);
        if(u <= 1e18) {
            q.push(u*10);
            q.push(u*10+1);
        }
    }
}
void solve() {
    ll n; cin >> n;
    int cnt = 0;
    for(ll x : v) {
        if(x <= n) cnt++;
        else break;
    }
    cout << cnt << endl;
}
int main() {
    int t; cin >> t;
    xuly();
    while(t--) {
        solve();
    }
}