#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct matrix
{
    ll f[2][2];
};
int mod = 1e9 + 7;
matrix operator * (matrix a, matrix b)
{
    matrix c;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
        {
            c.f[i][j] = 0;
            for (int k = 0; k < 2; k++)
                c.f[i][j] += (a.f[i][k]%mod * b.f[k][j]%mod);
                c.f[i][j] %= mod;
        }
    return c;
} 
matrix powMod(matrix a, int n)
{
    if(n == 1) return a;
    matrix x = powMod(a, n/2);
    if(n % 2 == 0) return x*x;
    return x*x*a;
}
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        matrix a;
        a.f[0][0] = a.f[0][1] = a.f[1][0] = 1;
        a.f[1][1] = 0;
        matrix res = powMod(a, n);
        cout << res.f[0][1] << endl;
    }
}