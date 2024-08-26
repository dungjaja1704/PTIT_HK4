#include <bits/stdc++.h>
using namespace std;

int F[1001][1001];

int main() {
    int n, V;
    cin >> n >> V;
    int w[n+1], v[n+1];
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 1; i <= n; i++) cin >> v[i];

    F[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= V; j++) {
            F[i][j] = F[i-1][j];
            if(j >= w[i]) F[i][j] = max(F[i-1][j], F[i-1][j-w[i]] + v[i]);
            else F[i][j] = F[i-1][j];
        }
    }
    cout << F[n][V] << endl;
}