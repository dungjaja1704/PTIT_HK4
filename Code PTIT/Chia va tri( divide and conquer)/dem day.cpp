#include<bits/stdc++.h>
using namespace std;
long long mod = 123456789;
long long powMod(long long a, long long n)
{
    if(n == 1) return a;
    long long x = powMod(a, n/2);
    if(n % 2 == 0) return (x*x)%mod;
    return (((x*x)%mod)*a)%mod;
}
int main()
{
    int t; cin >> t;
    while(t--){
        long long n;
        cin >> n;
        cout << powMod(2, n-1) << endl;
    }
}