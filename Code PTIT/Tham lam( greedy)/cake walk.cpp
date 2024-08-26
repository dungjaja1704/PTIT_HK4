#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int a[n];
    for(int &x : a) cin >> x;
    long long res = 0;
    sort(a, a+n, greater<int>());
    long long h = 1;
    for(int i = 0; i < n; i++)
    {
        res += h * a[i];
        h *= 2;
    }
    cout << res;
}