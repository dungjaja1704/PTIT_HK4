#include <bits/stdc++.h>
using namespace std;
int n, m, ok = 0; 
vector<int> ke[1001];
bool visited[1001];
int parent[1001];
void nhap()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }
}
void DFS(int u) {
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            parent[v] = u;
            DFS(v);
        }
        else if(v != parent[u]){
            ok = 1;
        }
    }
}
int main()
{
    nhap();
    DFS(1);
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}