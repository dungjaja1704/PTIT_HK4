#include <bits/stdc++.h>
using namespace std;

int n, m, st, color[100005];
vector<int> adj[100005];
int ok = 1;

void dfs(int u) {
    if(!ok) return;
    for(int v : adj[u]) {
        if(color[v] == 0) {
            color[v] = 3 - color[u];
            dfs(v);
        }
        else if(color[v] == color[u]) {
            ok = 0;
            return;
        }
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) adj[i].clear();
        memset(color, 0, sizeof(color));
        ok = 1;
        for(int i = 1; i <= m; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) {
            if(color[i] == 0) {
                color[i] = 1;
                dfs(i);
            }
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}