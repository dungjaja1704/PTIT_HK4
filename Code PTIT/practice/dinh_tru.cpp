#include <bits/stdc++.h>
using namespace std;

bool used[100005];
vector<int> adj[100005];
int cnt = 0, n, m;

void dfs(int u) {
    cnt++;
    used[u] = true;
    for(int v : adj[u]) {
        if(!used[v]) dfs(v);
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            used[i] = false;
            adj[i].clear();
            cnt = 0;
        }
        for(int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int res = 0; 
        for(int i = 1; i <= n; i++) {
            memset(used, false, sizeof(used));
            used[i] = true;
            cnt = 0;
            if(i == 1) dfs(2);
            else dfs(1);                                            
            if(cnt != n-1) 
                // res++;
                cout << i << " ";
        }
        // cout << res;
        cout << endl;
    }
}