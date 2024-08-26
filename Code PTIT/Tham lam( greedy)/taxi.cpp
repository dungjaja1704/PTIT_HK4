#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int d[5] = {0};
    int a[n];
    for(int &x : a)
    {
        cin >> x;
        d[x]++;
    }
    int res = 0;
    res += d[4];
    int res31 = min(d[3], d[1]);
    d[1] -= res31;
    d[3] -=res31;
    res += res31;
    int res22 = d[2]/2;
    d[2] = d[2] % 2;
    res += res22;
    if(d[2])
    {
        res++;
        d[1] -= min(2, d[1]); 
    }
    res += d[3];
    int res1111 = d[1]/4;
    if(d[1] % 4 != 0) res1111++;
    res += res1111;
    cout << res;
}