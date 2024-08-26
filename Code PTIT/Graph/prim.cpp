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

void prim(int s) {
    taken[s] = true;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for(auto it : adj[s]) {
        int t = it.first;
        if(!taken[t]) {
            q.push({it.second, t});
        }
    }
    long long d = 0, dem = 0;
    while(!q.empty()) {
        pair<int, int> e = q.top(); q.pop();
        int u = e.second, w = e.first;
        if(!taken[u]) {
            ++dem;
            taken[u] = true;
            d += w;
            for(auto it : adj[u]) {
                int t = it.first;
                if(!taken[t]) {
                    q.push({it.second, t});
                }
            }
        }
    }
    if(dem == n - 1){
        cout << d << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
}
int main() {
    nhap();
    prim(1);
}