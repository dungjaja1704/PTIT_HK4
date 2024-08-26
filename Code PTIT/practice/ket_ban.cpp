#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
bool used[100005];
vector<int> adj[100005];

void dfs(int u) {
    cnt++;
    used[u] = true;
    for(int v : adj[u]) {
        if(!used[v]) {
            dfs(v);
        }
    }
}

main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            used[i] = false;
            adj[i].clear();
        }
        for(int i = 0; i < m; i++) {
            int x, y; 
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int res = 1;
        for(int i = 1; i <= n; i++) {
            if(!used[i]) {
                cnt = 0;
                dfs(i);
                res = max(res, cnt);
            }
        }
        cout << res << endl;
    }
}