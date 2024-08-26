#include<bits/stdc++.h>
using namespace std;

int f[1001][1001];
char a[1001][1001];
int main()
{
    int n, m;
    cin >> n;
    m = n;
    int mod = 1e9 + 7;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    f[0][1] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m ; j++) {
            if(a[i][j] == '.') {
                f[i][j] = f[i-1][j] + f[i][j-1];
            } else {
                f[i][j] = 0;
            }
            f[i][j] %= mod;
        }
    }
    cout << f[n][m];
}