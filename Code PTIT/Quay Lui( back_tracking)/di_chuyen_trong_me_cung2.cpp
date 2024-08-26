#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100][100], n, check = 0;
string s;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};;
string path = "ULRD";
vector<string> res;
void nhap()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
} 
void Try(int i, int j)
{
    if(i == n && j == n)
    {
        check = 1;
        res.push_back(s);
    }
    for(int k = 0; k < 4; k++)
    {
        int u = i + dx[k];
        int v = j + dy[k];
        if(u >= 1 && u <= n && v >= 1 && v <= n && a[u][v] == 1)
        {
            a[u][v] = 0;
            s += path[k];
            Try(u, v);
            a[u][v] = 1;
            s.pop_back();
        }
    }
}
int main()
{
    nhap();
    if(a[1][1])
    {
        a[1][1] = 0;
        Try(1, 1);
        sort(res.begin(), res.end());
        for(string x: res)
        {
            cout << x << endl;
        }
        if(check == 0)
        {
            cout << -1 << endl;
        }
    }
    else cout << -1 << endl;
}