#include<bits/stdc++.h>
using namespace std;  
int main()
{
    int n; 
    int a[n+1], f[n+1] = {0};
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    map<int, int> mp;
    int t = 0;
    mp[0] = 1;
    long long cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] % 2 == 1) t++;
        else t--;
        f[i] = t;
        cnt += mp[f[i]];
        // cout << mp[f[i]] << " ";
        mp[f[i]]++;
    }
    cout << cnt << endl;
}