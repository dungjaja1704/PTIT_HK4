#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool prime[1000001];
void sang()
{
    ll n = 1000000;
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i = 2; i*i <= n; i++)
    {
        if(prime[i])
        {
            for(int j = i*i; j <= n; j+=i)
            {
                prime[j] = false;
            }
        }
    }
}
ll f[1000001];
int mod = 1e9 + 7;
int main()
{
    sang();
    f[0] = f[1] = 0;
    ll tich = 1;
    for(int i = 2; i <= 1000000; i++)
    {
        if(prime[i])
        {
            tich = tich * i;
            tich %= mod; 
        }
        f[i] = tich;
    }
    int t; 
    cin >> t;
    while(t--)
    {
       int n; cin >> n;;
       cout << f[n] << endl;
    }
}