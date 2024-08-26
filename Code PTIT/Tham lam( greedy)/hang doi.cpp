#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    sort(a, a+n);
    long long t = 0, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] >= t)
        {
            cnt++;
            t += a[i];
        }
    }
    cout << cnt;
}