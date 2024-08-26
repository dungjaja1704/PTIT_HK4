#include <bits/stdc++.h>
using namespace std;
int f[1001][1001];
int main()
{
    int t; cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.length();
        int m = s2.length();
        s1 = "0" + s1;
        s2 = "0" + s2;
        f[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i] == s2[j])
                    f[i][j] = f[i - 1][j - 1] + 1;
                else
                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
        cout << f[n][m];
        cout << endl;
    }
}