/*
IP 7
OP 4
{1,3,4,6} va {2,5,7}
{1,2,5,6} va {3,4,7}
{1,2,4,7} va {3,5,6}
{2,3,4,5} va {1,6,7}
*/
#include <bits/stdc++.h>
using namespace std;
int f[250005];
int main()
{
    int n; cin >> n;
    int s = n*(n+1)/2;
    int mod = 1e9+7;
    int res = 0;
    if (s % 2 == 0) {
        s /= 2;
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = s; j >= 1; j--) {
                if(j >= i) {
                    // co lay n
                    f[j] += f[j-i];
                    if (i == n && j == s) {
                        // khong lay n 
                        res = f[j-i];
                    }
                }
                f[j] %= mod;   
            }
        }
        cout << res;
    }
    else {
        cout << 0;
    }
}