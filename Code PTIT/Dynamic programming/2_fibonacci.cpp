#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9+7;
ll f[1000005];
void fibo()
{
    f[0] = 0;
    f[1] = 1;
    for(int i = 2; i <= 1000000; i++)
    {
        f[i] = f[i-1] + f[i-2];
        f[i] %= mod;
    }
}
int main()
{
    fibo();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << f[n] << endl;
    }
}