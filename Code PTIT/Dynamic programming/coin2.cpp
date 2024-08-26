#include <bits/stdc++.h>
using namespace std;
int f[1000001];
int main()
{
    int n, s; cin >> n >> s;
    int a[n+1];
    int mod = 1e9 + 7;
    f[0] = 1;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= s; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i >= a[j])
            {
                f[i] += f[i-a[j]];
            }
            f[i] %= mod;
        }
    }
    cout << f[s];
}