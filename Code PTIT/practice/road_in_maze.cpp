#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

int n, s1, s2, t1, t2, a[1005][1005];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{s1, s2}, 0});
    a[s1][s2] = 0;
    while(!q.empty()) {
        auto it = q.front(); q.pop();
        int x = it.fi.fi, y = it.fi.se, d = it.se;
        if(x == t1 && y == t2) return d;
        for(int k = 0; k < 8; k++) {
            int u = x + dx[k], v = y + dy[k];
            if(u >= 1 && u <= n && v >= 1 && v <= n && a[u][v] == 1) {
                a[u][v] = 0;
                q.push({{u, v}, d + 1});
            } 
        }
    }
    return -1;
} 

int main() {
    cin >> n; 
    cin >> s1 >> s2 >> t1 >> t2;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    cout << bfs();
}