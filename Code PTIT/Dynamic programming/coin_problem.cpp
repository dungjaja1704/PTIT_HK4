#include <bits/stdc++.h>
using namespace std;
int dp[1000001];
int main()
{
    int n, s; cin >> n >> s;
    int coin[n];
    for(int i = 1; i <= n; i++) cin >> coin[i];
    dp[0] = 0;
    for(int i = 1; i <= s; i++)
    {
        dp[i] = 1e9;
        for(int j = 1; j <= n; j++)
        {
            if(i - coin[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    if(dp[s] == 1e9) cout << -1 << endl;
    else cout << dp[s] << endl;
}