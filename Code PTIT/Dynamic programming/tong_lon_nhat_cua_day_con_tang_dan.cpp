#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; 
    cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], f[n];
        for(int &x : a) cin >> x;
        for(int i = 0; i < n; i++)
        {
            f[i] = a[i];
            for(int j = 0; j < i; j++)
            {
                if(a[i] > a[j])
                {
                    f[i] = max(f[i], f[j] + a[i]);
                }
            }
        }
        cout << *max_element(f, f + n);
        cout << endl;
    }
}