#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int parent[N];

bool hasCycle(int v, int par) {
    visited[v] = true;
    parent[v] = par;
    for (int u : adj[v]) {
        if (!visited[u]) {
            if (hasCycle(u, v)) return true;
        } else if (u != par) {
            return true;
        }
    }
    return false;
}

void solve() {
    int V, E;
    cin >> V >> E;
    for (int i = 1; i <= V; i++) {
        adj[i].clear();
        visited[i] = false;
    }
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= V; i++) {
        if (!visited[i] && hasCycle(i, -1)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}