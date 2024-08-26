#include<bits/stdc++.h>
using namespace std;
int n, a[505][505];
long long f[505][505];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        f[0][i] = -1e18;
        f[n+1][i] = -1e18;
    }
    for(int i = 1; i <= n; i++){
        f[i][1] = a[i][1];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[j][i] = max({f[j+1][i-1], f[j][i-1], f[j-1][i-1]}) + a[j][i];
        }
    }
    long long ans = -1e18;
    for(int i = 1; i <= n; i++){
        ans = max(ans, f[i][n]);
    }
    cout << ans << endl;
    return 0;
}