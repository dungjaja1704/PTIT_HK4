#include <bits/stdc++.h>
using namespace std;   
int main()
{
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> v;
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(v.begin(), v.end(), a[i]);
        if(it == v.end()) v.push_back(a[i]);
        else *it = a[i];
    }
    cout << v.size() << endl;
    for(auto x : v) cout << x << " ";
}