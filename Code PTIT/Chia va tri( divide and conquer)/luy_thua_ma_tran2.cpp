#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct matrix
{
    ll f[15][15];
};
int mod = 1e9 + 7;
ll n, k;
matrix operator * (matrix a, matrix b)
{
    matrix c;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            c.f[i][j] = 0;
            for (int k = 0; k < n; k++)
                c.f[i][j] += (a.f[i][k]%mod * b.f[k][j]%mod);
                c.f[i][j] %= mod;
        }
    return c;
} 
matrix powMod(matrix a, ll n)
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
        cin >> n >> k;
        matrix a;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cin >> a.f[i][j];
        }
        matrix res = powMod(a, k);
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
           sum += res.f[i][n-1];
           sum %= mod;
        }
        cout << sum << endl;
    }
}