#include <bits/stdc++.h>
using namespace std;

int n, m, parent[100005], sz[100005];
int size_max = 1;
int Find(int u) {
    if(u == parent[u]) return u;
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
    size_max = max({size_max, sz[x], sz[y]});
}
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    int cnt = n;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        if(Union(x, y)) cnt--;
        cout << cnt << " " << size_max << endl;
    }
}