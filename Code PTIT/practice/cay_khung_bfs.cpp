#include <bits/stdc++.h>
using namespace std;

bool used[100005];
vector<int> adj[100005];
int n, m, s;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    used[s] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) {
            if(!used[v]) {
                cout << u << " " << v << endl;
                used[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    bfs(s);
}