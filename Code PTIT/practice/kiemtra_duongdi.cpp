#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1005];
bool visited[1005];
int cnt = 0;
int tplt[1005];
void BFS(int u) {
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while(!q.empty()){
        int v = q.front(); q.pop();
        tplt[v] = cnt;
        for(int x : adj[v]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int main() {
    int T; cin >> T;
    while(T--) {
        int N, M; cin >> N >> M;
        for(int i = 1; i <= N; i++) {
            adj[i].clear();
            visited[i] = false;
        }
        for(int i = 0; i < M; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // because the graph is undirected
        }
        for(int i = 1; i <= N; i++) {
            if(!visited[i]){
                cnt++;
                BFS(i);
            }
        }
        int Q; cin >> Q;
        while(Q--) {
            int x, y; cin >> x >> y;
            if(tplt[x] == tplt[y]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}