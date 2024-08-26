#include <bits/stdc++.h>
using namespace std; 
vector<int> ke[1001];
bool visited[1001];
int n, m, s, t, dem = 0;
int ID[1001], parent[1001];
void nhap(){
    cin >> n >> m >> s >> t; 
    for(int i = 1; i <= n; i++) {
        ke[i].clear();
        visited[i] = false;
    }
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        // ke[y].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        sort(ke[i].begin(), ke[i].end());
    }
}
void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y : ke[x]) {
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
                parent[y] = x;
            }
        }
    }
}
void DFS(int u) {
    visited[u] = true;
    for(int v : ke[u]){
        if(!visited[v]){
            DFS(v);
            parent[v] = u;
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) 
    {
        nhap();
        DFS(s);
        if(!visited[t]) {
            cout << "-1\n";
        }
        else {
            vector<int> res;
            while(t != s){
                res.push_back(t);
                t = parent[t];
            }
            res.push_back(s);
            reverse(res.begin(), res.end());
            for(int x : res) cout << x << " ";
        }
    }
}