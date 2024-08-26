#include<bits/stdc++.h>
using namespace std;
struct Job{
    int id, deadline, profit;
};
bool cmp(Job a, Job b)
{
    return a.deadline > b.deadline;
}
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        Job a[n];
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].id >> a[i].deadline >> a[i].profit ;
        }
        sort(a, a+n, cmp);
        priority_queue<int> pq;
        int cur_date = a[0].deadline;
        int idx = 0, cnt = 0;
        long long res = 0;
        while(cur_date >= 1)
        {
            while(idx < n && a[idx].deadline >= cur_date)
            {
                pq.push(a[idx].profit);
                idx++;
            }
            if(!pq.empty())
            {
                res += pq.top();
                pq.pop();
                cnt++;
            }
            cur_date--;
        }
        cout << cnt << " " << res << endl;
    }
}