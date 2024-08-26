#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    queue<ll> q;
    vector<ll> v;
    q.push(9);
    while(1) {
        ll u = q.front(); q.pop();
        if(u > 1e18) break;
        v.push_back(u);
        q.push(u*10);
        q.push(u*10+9);
    }
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(ll x : v) {
            if(x % n == 0) {
                cout << x << "\n";
                break;
            }
        }
    }
}