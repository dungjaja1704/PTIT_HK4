#include <bits/stdc++.h>
using namespace std;

int n, m, bbv[1005];
vector<int> adj[1005];
bool used[1005];

void Kahn(){
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(bbv[i] == 0) q.push(i); 
    }
    vector<int> topo;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v : adj[u]) {
            bbv[v]--;
            if(bbv[v] == 0) q.push(v);
        }
    }
    if(topo.size() != n) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
            bbv[i] = 0;
        }
        for(int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
            bbv[y]++;
        }
        Kahn();
    }
}