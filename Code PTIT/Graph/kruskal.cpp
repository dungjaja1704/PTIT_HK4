#include<bits/stdc++.h>
using namespace std;

struct edge {
    int x, y, w;
};
int n, m;
int sz[100001], parent[100001];
vector<edge> dscanh;
void ktao()
{
    for(int i = 1; i <= n; i++) {
        sz[i] = 1;
        parent[i] = i;
    }
}

int find(int u) {
    if(u == parent[u]) {
        return u;
    }
    else {
        return parent[u] = find(parent[u]);
    }
}

bool Union(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) {
        return false;
    }
    if(sz[u] > sz[v]){
        parent[v] = u;
        sz[u] += sz[v];
    }
    else {
        parent[u] = v;
        sz[v] += sz[u];
    }
    return true;
}

void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        edge e{x, y, w};
        dscanh.push_back(e);
    }
}

void kruskal() {
    sort(dscanh.begin(), dscanh.end(), [](edge a, edge b)->bool {
        return a.w < b.w;
    });
    long long d = 0;
    vector<edge> MST;
    for(int i = 0; i < m; i++) {
        if(MST.size() == n - 1) break;
        edge e = dscanh[i];
        if(Union(e.x, e.y)) {
            MST.push_back(e);
            d += e.w;
        }
    }
    if(MST.size() < n - 1) {
        cout << "IMPOSSIBLE" << endl;
    }
    cout << d << endl;
    // for(auto it : MST) {
    //     cout << it.x << " " << it.y << " " << it.w << endl;
    // }
}
int main() {
    nhap();
    ktao();
    kruskal();
}