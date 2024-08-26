#include<bits/stdc++.h>
using namespace std;

const int MAX = 505;
const int INF = 1e9;
typedef pair<int, int> pii;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1}; 
int n, m, a[MAX][MAX], d[MAX][MAX];

bool isValid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void Dijkstra() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            d[i][j] = INF;
        }
    }
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    d[1][1] = a[1][1];
    pq.push({d[1][1], {1, 1}});
    while(!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        int x = u.first, y = u.second;
        if(du != d[x][y]) continue;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(isValid(nx, ny) && d[nx][ny] > d[x][y] + a[nx][ny]) {
                d[nx][ny] = d[x][y] + a[nx][ny];
                pq.push({d[nx][ny], {nx, ny}});
            }
        }
    }
    cout << d[n][m] << endl;
}

int main() {
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        Dijkstra();
    }
}