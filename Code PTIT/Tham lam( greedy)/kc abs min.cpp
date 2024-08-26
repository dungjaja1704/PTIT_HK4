#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    int min_val = 1e9;
    sort(a, a+n);
    for(int i = 1; i < n; i++)
    {
        min_val = min(min_val, a[i] - a[i-1]);
    }
    cout << min_val;
}