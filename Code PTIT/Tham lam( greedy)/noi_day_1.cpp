#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n];
        long long s = 0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int &x : a)
        {
            cin >> x;
            pq.push(x);
        }
        while(pq.size() >= 2)
        {
            long long s1 = pq.top(); pq.pop();
            long long s2 = pq.top(); pq.pop();
            long long k = s1 + s2;
            s += k;
            pq.push(k);
        }
        cout << s << endl;
    }
}