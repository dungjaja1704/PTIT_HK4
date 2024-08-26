#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, mod = 1e9 + 7; cin >> n;
        int a[n];
        int s = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int &x : a)
        {
            cin >> x;
            pq.push(x);
        }
        while(pq.size() >= 2)
        {
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            int k = (s1 + s2) % mod;
            s = (s + k) % mod;
            pq.push(k);
        }
        cout << s << endl;
    }
}