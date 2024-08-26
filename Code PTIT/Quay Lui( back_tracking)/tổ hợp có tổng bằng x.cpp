#include<bits/stdc++.h>
using namespace std;
int n, s, a[100], x[100];
bool used[10];
vector<vector<int>> v;
void ql(int i, int bd, int sum)
{
    for(int j = bd; j <= n; j++)
    {
        if(sum + a[j] <= s)
        {
            x[i] = a[j];
            if(sum + a[j] == s)
            {
                vector<int> tmp(x+1, x+i+1);
                v.push_back(tmp);
            }
            else ql(i+1, j, sum+a[j]);
        }
    }
}
int main()
{
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    ql(1, 1, 0);
    if(v.size() == 0) cout << -1;
    else
    {
        cout << v.size() << endl;
        for(auto it : v)
        {
            cout << "{";
            for(int i = 0; i < it.size(); i++)
            {
                cout << it[i];
                if(i < it.size()-1) cout <<" ";
            }
            cout <<"}\n";
        }
    }
}
