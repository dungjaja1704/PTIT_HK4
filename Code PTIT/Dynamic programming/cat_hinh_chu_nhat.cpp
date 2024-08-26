#include <bits/stdc++.h>
using namespace std;
// thanh cac hinh vuong
// IP 3 5
// OP 3
int n, m, f[1005][1005];
int tinh(int n, int m)
{
    if (n == m) return 0;
    if (f[n][m] != 0) return f[n][m];
    int res = 1e9;
    // cat theo chieu doc
    for(int i = 1; i <= m-1; i++) {
        res = min(res, tinh(n, i) + tinh(n, m-i) + 1);
    }
    // cat theo chieu ngang
    for(int i = 1; i <= n-1; i++) {
        res = min(res, tinh(i, m) + tinh(n-i, m) + 1);
    }
    return f[n][m] = res;
}
int main() 
{
    cin >> n >> m;
    cout << tinh(n, m);
}
