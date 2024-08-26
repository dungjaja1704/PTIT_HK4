#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100005];
bool used[100005];
int res = 0;
int dfs(int u) {
    int cnt = 1;
    used[u] = true;
    for(int v : adj[u]) {
        if(!used[v]) {
            cnt += dfs(v);
        }
    }
    res += cnt;
    return cnt;
}
int main() {
    cin >> n;
    for(int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    cout << res;
}