#include <bits/stdc++.h>
using namespace std;

vector<string> v;
void xuly() {
    queue<string> q;
    q.push("6");
    q.push("8");
    while(!q.empty()) {
        string u = q.front(); q.pop();
        if(u.length() > 15) break;
        v.push_back(u);
        q.push(u + "6");
        q.push(u + "8");
    }
}
void solve() {
    int n; cin >> n;
    vector<string> res;
    for(string x : v) {
        if(x.length() > n) break;
        res.push_back(x);
    }
    cout << res.size() << endl;
    for(string x : res) cout << x << " ";
    cout << endl;
}
int main() {
    xuly();
    int t; cin >> t;
    while(t--) {
        solve();
    }
}