#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, c[100][100], x[100], ans = INT_MAX, cmin = INT_MAX;
int visited[100]; 
int cost = 0;
void Try(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(visited[j] == 0)
        {
            x[i] = j;
            visited[j] = 1;
            cost += c[x[i - 1]][x[i]];
            if(i == n)
            {
                ans = min(ans, cost + c[x[n]][1]);
            }
            else if(cost + (n - i + 1) * cmin < ans)
            {
                Try(i + 1);
            }
            visited[j] = 0;
            cost -= c[x[i - 1]][x[i]];
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if(i != j)
            {
                cmin = min(cmin, c[i][j]);
            }
        }
    }
    x[1] = 1;
    visited[1] = 1;
    Try(2);
    cout << ans << endl;
}