#include <bits/stdc++.h>
using namespace std;

bool used[100005];
int n, m, res = 0, d[100005];
vector<int> adj[100005];

void dfs(int u, int lt) {
    used[u] = true;
    int ok = 0;
    for(int v : adj[u]) {
        if(!used[v]) {
            ok = 1;
            if(d[v] == 1 && lt+1 <= m) {
                dfs(v, lt+1);
            }
            else if(d[v] == 0) {
                dfs(v, 0);
            }
        }
    }
    if(!ok) res++;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, d[1]);
    cout << res;
}