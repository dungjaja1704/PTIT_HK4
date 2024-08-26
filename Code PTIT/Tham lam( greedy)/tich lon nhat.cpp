#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    long long a[n];
    for(long long &x : a) cin >> x;
    sort(a, a+n);
    if(n>3){
        cout << max({a[0]*a[1], a[n-1]*a[n-2], a[n-1]*a[n-2]*a[n-3], a[0]*a[1]*a[n-1]});
    }
    else
    {
        cout << max({a[0]*a[1], a[n-1]*a[n-2]});
    }
}