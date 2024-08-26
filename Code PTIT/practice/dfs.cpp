#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<int> adj[1005];
bool used[1005];
void dfs(int u) {
    cout << u << " ";
    used[u] = true;
    for(int v : adj[u]) {
        if(!used[v]) {
            dfs(v);
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> m >> s;
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
            used[i] = false;
        }
        for(int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        for(int i = 1; i <= n; i++) {
            sort(adj[i].begin(), adj[i].end());
        }
        dfs(s);
        cout << endl;
    }
}