#include<bits/stdc++.h>
using namespace std;
int n, s = 0, a[100], x[100], ok = 0;
void ql(int i, int bd, int sum){
    if(ok) return;
    for(int j = bd; j <= n; j++){
        if(sum + a[j] <= s){
            x[i] = a[j];
            if(sum + a[j] == s) ok = 1;
            else ql(i+1, j+1, sum+a[j]);
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s += a[i];
    }
    if(s % 2 == 1){
        cout << 0;
        return 0;
    }
    s /= 2;
    sort(a+1, a+n+1);
    ql(1, 1, 0);
    cout << ok;
}
