// 27
// 5
// cmt 27->20->18->10->9->0 xoa so buoc toi thieu
#include <bits/stdc++.h>
using namespace std;
int f[1000001];
// QHD tu tren xuong duoi
int tinh(int n)
{
    if(n == 0) return 0;
    if(f[n] != 0) return f[n];
    int m = n;
    int res = 1e9;
    while(m) {
        int r = m % 10;
        if(r != 0) {
            res = min(res, tinh(n-r) + 1);
        }
        m /= 10;
    }
    f[n] = res;
    return res;
}

int main()
{
    int n; cin >> n;
    cout << tinh(n);
}

// QHD tu duoi len tren
/*
int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        f[i] = 1e9;
        int m = i;
        while(m) {
            int r = m % 10;
            if(r != 0) {
                f[i] = min(f[i], f[i-r] + 1);
            }
            m /= 10;
        }
    }
    cout << f[n];
}
*/