#include<bits/stdc++.h>
using namespace std;
int f[101][1000001];
int main()
{
    int n, s; cin >> n >> s;
    int a[n+1];
    int mod = 1e9 + 7;
    for(int i = 0; i <= n; i++) f[i][0] = 1;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= s; j++)
        {
            if(j >= a[i])
            {
                f[i][j] = f[i][j-a[i]] + f[i-1][j];
            }
            else f[i][j] = f[i-1][j];
            f[i][j] %= mod;
        }
    }
    cout << f[n][s];
}