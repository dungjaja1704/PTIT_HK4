#include <bits/stdc++.h>
using namespace std;
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m, k;
//         cin >> n >> m >> k;
//         int a[n], b[m], p1 = 0, p2 = 0, ans;
//         for (int i = 0; i < n; i++)
//             cin >> a[i];
//         for (int i = 0; i < m; i++)
//             cin >> b[i];
//         while (k--)
//         {
//             if (p1 == n - 1)
//                 ans = b[p2++];
//             if (p2 == m - 1)
//                 ans = a[p1++];
//             if (a[p1] < b[p2])
//             {
//                 ans = a[p1];
//                 p1++;
//             }
//             else
//             {
//                 ans = b[p2];
//                 p2++;
//             }
//         }
//         cout << ans << endl;
//     }
// }
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m, k; cin >> n >> m >> k;
        int a[n], b[m];
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        vector<int> v;
        int i = 0, j = 0;
        while(i < n && j <m)
        {
            if(a[i] <= b[j])
            {
                v.push_back(a[i++]);
            }
            else
            {
                v.push_back(b[j++]);
            }
        }
        while(i < n) v.push_back(a[i++]);
        while(j < m) v.push_back(b[j++]);
        cout << v[k-1] << endl;
    } 
}