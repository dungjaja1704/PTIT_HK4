// cau thang
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 1e9+7;
ll f[100001];
int main()
{
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= k; j++)
            {
                if(i >= j)
                {
                    f[i] += f[i-j];
                    f[i] %= mod;
                }
            }
        }
        cout << f[n];
        cout << endl;
    }
}