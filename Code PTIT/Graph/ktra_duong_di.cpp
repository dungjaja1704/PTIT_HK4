#include <bits/stdc++.h>
using namespace std; 
vector<int> ke[1001];
bool visited[1001];
int n, m, dem = 0;
int ID[1001];
void nhap(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
            ke[i].clear();
            visited[i] = false;
    }
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
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
        ID[x] = dem; 
        // cout << x << " ";
        for(int y : ke[x]) {
            if(!visited[y]){
                q.push(y);
                visited[y] = true;
            }
        }
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        nhap();
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                ++dem;
                BFS(i);
            }
        }
        int q; cin >> q;
        while(q--) {
            int x, y; cin >> x >> y;
            if(ID[x] == ID[y]){
                cout << "YES\n";
            }
            else cout << "NO\n"; 
        }
    }
}