#include <bits/stdc++.h>
using namespace std;
int tim(int a[], int b[], int n)
{
    int l = 0, r = n - 2, res = -1;
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(a[mid] == b[mid])
        { 
            l = mid + 1;
        }
        else
        {
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int a[n], b[n-1];
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        cout << tim(a, b, n) + 1 << endl;
    }
}