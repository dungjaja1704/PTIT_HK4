#include <bits/stdc++.h>
using namespace std;

bool used[100005];
vector<int> adj[10005];
int cnt = 0, canh_hoan_hao = 0;
int n, m;

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
            canh_hoan_hao = 0;
        } 
        for(int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        canh_hoan_hao = 0;
        for(int i = 1; i <= n; i++) {
            if(!used[i]) {
                cnt = 0;
                dfs(i);
                canh_hoan_hao += cnt*(cnt-1)/2;
            }
        }
        if(m == canh_hoan_hao) cout << "YES\n";
        else cout << "NO\n";
    }
}