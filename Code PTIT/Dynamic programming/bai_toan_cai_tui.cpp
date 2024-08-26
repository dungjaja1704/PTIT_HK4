#include <bits/stdc++.h>
using namespace std;
int f[1001][1001];
int main()
{
    int n, c;
    cin >> n >> c;
    int w[n + 1], v[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= c; j++)
        {
            if(j >= w[i])
                f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
            else
                f[i][j] = f[i - 1][j];
        }
    }
    cout << f[n][c];
}