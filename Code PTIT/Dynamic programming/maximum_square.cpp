#include<bits/stdc++.h>
using namespace std;

int a[1001][1001];
int f[1001][1001];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    int res = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == 1) {
                f[i][j] = min({f[i-1][j-1], f[i][j-1], f[i-1][j]}) + 1;
            } else {
                f[i][j] = 0;
            }
            res = max(res, f[i][j]);
        }
    }
    cout << res;
}