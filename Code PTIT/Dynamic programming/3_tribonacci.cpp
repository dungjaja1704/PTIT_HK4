#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9+7;
ll f[1000005];
void fibo()
{
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    for(int i = 3; i <= 1000000; i++)
    {
        f[i] = (f[i-1]%mod + f[i-2]%mod + f[i-3]%mod)%mod;
    }
}
int main()
{
    int t; cin >> t;
    fibo();
    while(t--)
    {
        int n; cin >> n;
        cout << f[n-1] << endl;
    }
}