#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int k;
    string s;
    cin >> k >> s;
    int d[256] = {0};
    for(char c : s) d[c]++;
    priority_queue<int> pq;
    for(int i = 0; i < 256; i++)
    {
        if(d[i]) pq.push(d[i]);
    }
    while(k-- && pq.size())
    {
        int u = pq.top(); pq.pop();
        if(u-1>=1) pq.push(u-1);
    }
    long long res = 0;
    while(!pq.empty()){
        int u = pq.top(); pq.pop();
        res += (long long) u * u;
    }
    cout << res << endl;
}
int main()
{
    int t; cin >> t;
    while(t--){
        solve();
    }
}