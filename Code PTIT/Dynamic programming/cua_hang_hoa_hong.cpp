#include<bits/stdc++.h>
using namespace std;
// tinh day tang dan tu trai qua phai co the loai bo nhieu nhat 1 phan tu
int main()
{
    int n; cin >> n;
    int a[n+1], t[n+1] = {0}, g[n+1] = {0};
    for(int i = 1; i <= n; i++) cin >> a[i];
    t[1] = 1;
    int res = 1;
    // khong bo 1 phan tu
    for(int i = 2; i <= n; i++) {
        if(a[i] > a[i-1]) {
            t[i] = t[i-1] + 1;
        }
        else t[i] = 1;
        res = max(res, t[i]);
    }
    g[n] = 1;
    for(int i = n-1; i >= 1; i--) {
        if(a[i] < a[i+1]) {
            g[i] = g[i+1] + 1;
        }
        else g[i] = 1;
    }
    // bo 1 phan tu
    for(int i = 2; i <= n; i++) {
        if(a[i-1] < a[i+1]) {
            res = max(res, t[i-1] + g[i+1]);
        }
    }
    cout << res;
}
// 8
// 3 4 5 2 6 7 8 2
// 1 2 3 1 2 3 4 1
// 3 2 1 4 3 2 1 1