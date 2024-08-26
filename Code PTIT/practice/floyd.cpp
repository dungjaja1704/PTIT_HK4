#include <bits/stdc++.h>
using namespace std;
int n, m, a[105][105];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) a[i][j] == 0;
            else a[i][j] = 1e9;
        } 
    }
    for(int i = 0; i < m; i++) {
        int x, y, z; cin >> x >> y >> z;
        a[x][y] = z;
        a[y][x] = z;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        } 
    }
    int q; cin >> q;
    while(q--) {
        int x, y; cin >> x >> y;
        cout << a[x][y] << endl;
    }
}