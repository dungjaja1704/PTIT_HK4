#include<bits/stdc++.h>
using namespace std;
int n, a[505][505], f[505][505];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[i][j] = max({f[i - 1][j], f[i - 1][j - 1], f[i-1][j+1]}) + a[i][j];
        }
    }
    int res = 0;
    for(int i = 1; i <= n; i++){
        res = max(res, f[n][i]);
    }
    cout << res << endl;
}