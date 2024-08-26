#include <bits/stdc++.h>
using namespace std;

int n, m, st, d[1005];
vector<pair<int, int>> adj[1005];

void Bellman_Ford(int st) {
    for(int i = 1; i <= n; i++) {
        d[i] = 1e9;
    }
    d[st] = 0;
    for(int i = 0; i < n-1; i++) {
        for(int u = 1; u <= n; i++) {
            for(auto it : adj[u]) {
                int v = it.second, len = it.first;
                d[v] = min(d[v], d[u] + len);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
}

int main() {
    cin >> n >> m >> st;
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        adj[x].push_back({z, y});
        adj[y].push_back({z, x});
    }
    Bellman_Ford(st);
}