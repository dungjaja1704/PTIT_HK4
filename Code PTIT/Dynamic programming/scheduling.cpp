/*
4
2 4 4
3 6 6
6 8 2
5 7 3
OP 7
*/
#include <bits/stdc++.h>
using namespace std;
struct Job {
    int start, end;
    long long profit;
};
bool cmp(Job a, Job b) {
    return a.end < b.end;
}
int first_pos(Job a[], int i, int x)
{
    int l = 1, r = i - 1, res = - 1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(a[mid].end <= x) {
            res = mid;
            l = mid + 1;
        } 
        else r = mid - 1;
    }
    return res;
}
Job a[200001];
long long F[200001] = {0};

long long tinh(int n) {
    if(n == 0) return 0;
    if(F[n] != 0) return F[n];
    F[n] = 0;
    int t = first_pos(a, n, a[n].start - 1);
    if(t != -1) {
        F[n] = max(a[n].profit + tinh(t), tinh(n-1));
    }
    else {
        F[n] = max(a[n].profit + 0, tinh(n-1));
    }
    return F[n];
}
int main()
{
    int n; cin >> n;
    // long long F[n+1] = {0};
    // Job a[n+1];
    for(int i = 1; i <= n; i++)
        cin >> a[i].start >> a[i].end >> a[i].profit;
    sort(a+1, a+n+1, cmp);
    // for(int i = 1; i <= n; i++) {
    //     int t = first_pos(a, i, a[i].start-1);
    //     if(t == -1) {
    //         F[i] = max(a[i].profit + 0, F[i-1]);
    //     }
    //     else F[i] = max(a[i].profit + F[t], F[i-1]);
    // }
    // cout << F[n];
    cout << tinh(n);
}