#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n = 8, a[100][100], x[100], ans = 0, cot[100], xuoi[100], nguoc[100];
void Try(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(cot[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j - 1] == 0)
        {
            x[i] = j;
            cot[j] = 1; xuoi[i - j + n] = 1; nguoc[i + j - 1] = 1;
            if(i == n)
            {
                int tong = 0;
                for(int hang = 1; hang <= n; hang++)
                {
                    tong += a[hang][x[hang]];
                }
                ans = max(ans, tong);
            }
            else
            {
                Try(i + 1);
            }
            cot[j] = 0; xuoi[i - j + n] = 0; nguoc[i + j - 1] = 0;
        }
    }
}
int main()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    Try(1);
    cout << ans;
}