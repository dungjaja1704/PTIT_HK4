#include <bits/stdc++.h>
using namespace std;

struct edge{
    int st, ed, w;
};

int n, m, parent[100005], sz[100005];
bool cmp(edge a, edge b) {
    return a.w < b.w;
}
int Find(int u) {
    if(parent[u] == u) return u;
    return parent[u] = Find(parent[u]);
}
bool Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if(x == y) return false;
    if(sz[x] > sz[y]) {
        parent[y] = x;
        sz[x] += sz[y];
    }
    else {
        parent[x] = y;
        sz[y] += sz[x];
    }
    return true;
}
int main(){
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
        vector<edge> canh;
        vector<edge> mst;
        for(int i = 0; i < m; i++) {
            int x, y, z; cin >> x >> y >> z;
            canh.push_back(edge{x, y, z});
        }
        sort(canh.begin(), canh.end(), cmp);
        long long cost = 0;
        for(edge e : canh) {
            if(Union(e.st, e.ed)) {
                cost += e.w;
                mst.push_back(e);
            }
        }
        if(mst.size() == n-1) cout << cost << endl;
        else cout << "IMPOSSIBLE\n"; 
    }
}