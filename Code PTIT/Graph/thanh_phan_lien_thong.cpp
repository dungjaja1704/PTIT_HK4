#include<bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
int a[1001][1001];
vector<pair<int, int>> dscanh;
bool visited[1001];
int n, m;

void DFS1(int u){
    // cout << u << " ";
    visited[u] = true;
    // duyet ds ke cua dinh u
    for(int v : ke[u]){
        if(!visited[v]){
            DFS1(v);
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    int dem = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            DFS1(i);
            ++dem;
        }
    }
    cout << dem << endl;
}