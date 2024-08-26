// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
// {
//     int n, k; cin >> n >> k;
//     vector<ll> a(n), dp(n);
//     for(int i = 0; i < n; i++) cin >> a[i];
//     dp[0] = 0;
//     if(n > 1) dp[1] = abs(a[1] - a[0]);
//     for(int i = 2; i < n; i++) {
//         dp[i] = min({dp[i-1] + abs(a[i] - a[i-1]),
//                      dp[i-2] + abs(a[i] - a[i-2]),
//                      dp[i-k] + abs(a[i] - a[i-k])});
//     }
//     cout << dp[n-1] << endl;
// }
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n, k; cin >> n >> k;
    vector<ll> a(n), dp(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    dp[0] = 0;
    for(int j = 1; j <= min(n-1, k); j++) dp[j] = abs(a[j] - a[0]);
    for(int i = k+1; i < n; i++) {
        dp[i] = dp[i-1] + abs(a[i] - a[i-1]);
        for(int j = 2; j <= k; j++) {
            dp[i] = min(dp[i], dp[i-j] + abs(a[i] - a[i-j]));
        }
    }
    cout << dp[n-1] << endl;
}