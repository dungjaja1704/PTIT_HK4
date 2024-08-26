#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
vector<int> adj[1005];
bool used[1005];

void dfs(int u) {
    used[u] = true;
    cnt++;
    for(int v : adj[u]) {
        if(!used[v]) {
            dfs(v);
        }
    } 
}

int check() {
    for(int i = 1; i <= n; i++) {
        cnt = 0;
        memset(used, false, sizeof(used));
        dfs(i);
        if(cnt != n) return 0;
        else return 1;
    }
} 

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
            used[i] = false;
        }
        for(int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        if(check()) cout << "YES\n";
        else cout << "NO\n";
    }
}