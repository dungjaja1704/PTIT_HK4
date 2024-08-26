#include <bits/stdc++.h>
using namespace std;
int n, m, timer = 0;
vector<int> ke[100001];
bool visited[100001];
int disc[100001], low[100001];
void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS(int u) {
    disc[u] = low[u] = ++timer;
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else {
            low[u] = min(low[u], disc[v]);
        }
    }
}
int main() {
    nhap();
    DFS(1);
    for(int i = 1; i <= n; i++) {
        cout << disc[i] << " " << low[i] << endl;
    }
}