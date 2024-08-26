#include <bits/stdc++.h>
using namespace std;
#define ll long long
// ll crossingSum(int a[], int l, int r, int mid)
// {
//     ll sumLeft = 0, maxSumLeft = 0;
//     ll sumRight = 0, maxSumRight = 0;
//     for(int i = mid; i >= l; i--)
//     {
//         sumLeft += a[i];
//         maxSumLeft = max(maxSumLeft, sumLeft);
//     }
//     for(int i = mid+1; i <= r; i++)
//     {
//         sumRight += a[i];
//         maxSumRight = max(maxSumRight, sumRight);
//     }
//     return maxSumLeft + maxSumRight;
// }
// ll maxSum(int a[], int l, int r)
// {
//     if(l == r) return a[l];
//     int mid = (l+r)/2;
//     return max({
//         maxSum(a, l, mid),
//         maxSum(a, mid+1, r),
//         crossingSum(a, l, r, mid)
//     });
// }
int main()
{
    int t; cin >> t;
    while(t--){
        // int n; cin >> n;
        // int a[n];
        // for(int &x : a) cin >> x;
        // cout << maxSum(a, 0, n-1);
        int n;
        cin >> n;
        int x, ans = 0, s = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            s += x;
            ans = max(ans, s);
            if (s < 0)
                s = 0;
        }
        cout << ans << endl;
    }
}