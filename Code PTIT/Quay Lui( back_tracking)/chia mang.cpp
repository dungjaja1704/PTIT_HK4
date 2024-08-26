#include<bits/stdc++.h>
using namespace std;
int n, k, sum = 0, a[100], x[100];
bool used[105];
int ok = 0;
void ql(int i, int bd, int cur_sum, int cnt)
{
    if(cnt == k+1)
    {
        ok = 1;
        return;
    }
    for(int j = bd; j <= n; j++)
    {
        if(!used[j] && cur_sum + a[j] <= sum)
        {
            x[i] = a[j];
            used[j] = true;
            if(cur_sum + a[j] == sum)
            {
                ql(i+1, 1, 0, cnt+1);
            }
            else
            {
                ql(i+1, j+1, cur_sum + a[j], cnt);
            }
            used[j] = false;
        }
    }
}
int main()
{
    int t; cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if(sum % k == 0)
        {
            sum /= k;
            ql(1, 1, 0, 1);
            cout << ok << endl;
        }
        else cout << 0 << endl;
    }
}