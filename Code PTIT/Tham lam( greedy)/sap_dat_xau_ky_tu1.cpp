#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        string s; cin >> s;
        int d[256] = {0};
        int Max = 0;
        for(char c : s)
        {
            d[c]++;
            Max = max(Max, d[c]);
        }
        int n = s.length();
        if(Max <= (n-1)/2+1) cout << 1 << endl;
        else cout << -1 << endl;
    }
}