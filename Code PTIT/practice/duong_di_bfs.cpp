#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> adj[1005];
bool visited[1005];
int parent[1005];

void BFS(int u) {
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int x : adj[v]){
            if(!visited[x]){
                visited[x] = true;
                parent[x] = v;
                q.push(x);
            }
        }
    }
}

void printPath(int t) {
    if(!visited[t]) {
        cout << "-1";
        return;
    }
    vector<int> path;
    while(t != -1) {
        path.push_back(t);
        t = parent[t];
    }
    reverse(path.begin(), path.end());
    for(int v : path) {
        cout << v << " ";
    }
}

int main() {
    int T; cin >> T;
    while(T--) {
        cin >> n >> m >> s >> t;
        for(int i = 1; i <= n; i++) {
            adj[i].clear();
            visited[i] = false;
            parent[i] = -1;
        }
        for(int i = 0; i < m; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        BFS(s);
        printPath(t);
        cout << endl;
    }
    return 0;
}