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
int f[1000001];
int main()
{
    sang();
    int dem = 0;
    for(int i = 0; i <= 1000000; i++)
    {
        if(prime[i]){
            dem++;
        }
        f[i] = dem;
    }
    int t; 
    cin >> t;
    while(t--)
    {
        int l, r; cin >> l >> r;
        cout << f[r] - f[l-1] << endl;
    }
}