#include<bits/stdc++.h>
using namespace std;
bool f[201][1000001];
int main()
{
    int n, s; cin >> n >> s;
    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) f[i][0] = true;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= s; j++)
        {
            if(j < a[i]) 
            {
                f[i][j] = f[i-1][j];
            }
            else
            {
                f[i][j] = f[i-1][j-a[i]] || f[i-1][j];
            }
        }
    }
    cout << f[n][s];
}

