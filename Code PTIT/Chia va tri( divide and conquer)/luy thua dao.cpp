#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9+7;
int rev(int n)
{
    int res = 0;
    while(n)
    {
        res = res*10 + n%10;
        n/=10;
    }
    return res;
}
ll powMod(ll a, ll n)
{
    if(n == 0) return 1;
    ll t = powMod(a,n/2);
    if(n % 2 == 0) return (t*t)%mod;
    return (((t*t)%mod)*a)%mod;
}
int main()
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << powMod(n, rev(n)) << endl;
    }
}