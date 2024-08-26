#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, a[100], x[100], ok;

void sinh() {
    int i = n;
    while(i >= 1 && x[i] == 1) {
        x[i] = 0;
        i--;
    }
    if(i == 0) ok = 0;
    else x[i] = 1;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ok = 1;
    ll res = 1e18;
    while(ok) {
        ll sum0 = 0, sum1 = 0;
        for(int i = 1; i <= n; i++) {
            if(x[i]) sum1 += a[i];
            else sum0 += a[i];
        }
        ll kc = abs(sum0 - sum1);
        res = min(res, kc);
        sinh();
    }
    cout << res;
}