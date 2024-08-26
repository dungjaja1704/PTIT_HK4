#include<bits/stdc++.h>
using namespace std;
int f[10000001];
int main()
{
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            f[i] = 1;
            for(int j = 0; j < i; j++)
                if(a[j] <= a[i]) f[i] = max(f[i], f[j] + 1);
            res = *max_element(f, f + n);
        }
        cout << n-res << endl;
    }
}