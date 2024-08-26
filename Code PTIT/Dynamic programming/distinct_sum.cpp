#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, s = 0;
    cin >> n;
    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
    }
    bool f[s+1];
    memset(f, false, sizeof(f));
    f[0] = true;
    for(int i = 1; i <= n; i++) {
        for(int j = s; j >= 1; j--) {
            if(j >= a[i]) {
                f[j] = f[j] || f[j-a[i]];
            } 
        }
    }
    for(int i = 0; i <= s; i++) {
        if(f[i]) cout << i << " ";
    }
}