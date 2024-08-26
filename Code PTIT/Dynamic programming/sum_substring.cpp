#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    s = "0" + s;
    long long sum = 0;
    long long f[n+1] = {0};
    for(int i = 1; i <= n; i++) {
        f[i] = f[i-1]*10 + i*(s[i] - '0');
        sum += f[i];
    } 
    //cout << s[0];
    cout << sum;
}
/* 235
   F1 = 2;
   F2 = 2*10 + 3*2 = 26;
   F3 = 26*10 + 5*3 = 275;
*/