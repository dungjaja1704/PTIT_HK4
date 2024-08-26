#include<bits/stdc++.h>
using namespace std;
// f[100] = 1;
// f[20] = 2^2 + 4^2 => f[20] = 2;
int main()
{
    int n; cin >> n;
    int f[n+1] = {0};
    f[1] = 1;
    for(int i = 2; i <= n; i++) {
        f[i] = i;
        for(int j = 1; j <= sqrt(i); j++) {
            f[i] = min(f[i], 1 + f[i - j*j]);
        }
    }
    cout << f[n];
}