#include <bits/stdc++.h>
using namespace std;
struct edge {
    int x, y, w;
};
int n, m;
bool taken[100001];
vector<pair<int, int>> adj[100001];

void nhap() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void dijkstra(int s) {
    vector<int> d(n + 1, 1e9);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while(!q.empty()) {
        pair<int, int> e = q.top(); q.pop();
        int u = e.second, kc = e.first;
        if(kc > d[u]) continue;
        for(auto it : adj[u]) {
            int v = it.first, w = it.second;
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << d[i] << " ";
}
int main() {
    nhap();
    dijkstra(1);
}