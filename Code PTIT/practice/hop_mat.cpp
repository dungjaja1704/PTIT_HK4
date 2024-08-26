#include <bits/stdc++.h>
using namespace std;

bool used[100005];
vector<int> adj[100005];
int k, n, m, d[100005];
void dfs(int u) {
    d[u]++;
    used[u] = true;
    for(int v : adj[u]) {
        if(!used[v]) dfs(v);
    }
}

int main() {
    cin >> k >> n >> m;
    int nguoi[k];
    for(int &x : nguoi) {
        cin >> x;
    } 
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int x : nguoi) {
        memset(used, false, sizeof(used));
        dfs(x);
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(d[i] == k) res++;
    } 
    cout << res;
}