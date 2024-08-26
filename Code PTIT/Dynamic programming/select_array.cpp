// IP 3 5
//    2 0 2
// OP 3
//[2, 1, 2], [2, 2, 2], [2, 3, 2]
/*
    Số đăng sau phải xét số đắng trước 
    F[3][2] = F[2][2] + F[2][1] + F[2][3]
    i: vị trí số 3 điền 2 khi vị trí số 2 điền 2, 1, 3
*/
#include <bits/stdc++.h>
using namespace std;
long long F[100001][101]; // tuy de cho
int main() 
{
    int n, m;
    cin >> n >> m;
    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int mod = 1e9 + 7;
    if(a[1] != 0) {
        F[1][a[1]] = 1;
    } 
    else {
        for(int j = 1; j <= m; j++)
            F[1][j] = 1;
    }
    for(int i = 2; i <= n; i++) {
        if(a[i] == 0) {
            for(int j = 1; j <= m; j++) {
                F[i][j] = F[i-1][j-1] + F[i-1][j] + F[i-1][j+1];
                F[i][j] %= mod;
            }
        }
        else {
            F[i][a[i]] = F[i-1][a[i]-1] + F[i-1][a[i]] + F[i-1][a[i]+1];
            F[i][a[i]] %= mod;
        }
    }
    int res = 0;
    for(int j = 1; j <= m; j++) {
        res += F[n][j];
        res %= mod;
    }
    cout << res;
}
