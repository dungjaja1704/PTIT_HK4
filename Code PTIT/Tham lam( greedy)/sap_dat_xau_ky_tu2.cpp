#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {   
        int d; cin >> d;
        string s; cin >> s;
        int x[256] = {0};
        int Max = 0;
        for(char c : s)
        {
            x[c]++;
            Max = max(Max, x[c]);
        }
        int n = s.length();
        if(Max <= (n-1)/d+1) cout << 1 << endl;
        else cout << -1 << endl;
    }
}