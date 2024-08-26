#include <bits/stdc++.h>
using namespace std;
int f[1002][1002];
int main()
{
    int n, m; cin >> n >> m;
    int a[n+1][m+1];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    // for(int i = 0; i <= n; i++) f[i][0] = 0;
    // for(int j = 0; j <= m; j++) f[0][j] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            f[i][j] = max({f[i - 1][j], f[i - 1][j - 1], f[i][j - 1]}) + a[i][j];
        }
    }
    cout << f[n][m] << endl;
}