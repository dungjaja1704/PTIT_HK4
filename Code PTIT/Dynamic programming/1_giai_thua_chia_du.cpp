#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int mod = 1e9+7;
ll f[1000005];
void gt()
{
    f[0] = 1;
    for(int i = 1; i <= 1000005; i++)
    {
        f[i] = (f[i-1]*i);
        f[i] %= mod;
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    gt();
    while(t--)
    {
        ll n; cin >> n;
        cout << f[n] << endl;
    }
}