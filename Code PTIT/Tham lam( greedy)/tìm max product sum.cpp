#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{   
    int t; cin >> t;
    while(t--)
    {
        int n;
        cin >> n; 
        int a[n];
        ll sum = 0;
        ll mod = 1e9 + 7;
        for(int &x : a) cin >> x;
        sort(a, a+n);
        for(int i = 0; i < n; i++)
        {
            sum += (1ll * a[i] * i) ;
            sum %= mod;
        }
        cout << sum << endl;
    }
}