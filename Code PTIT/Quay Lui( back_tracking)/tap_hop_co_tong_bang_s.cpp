#include<bits/stdc++.h>
using namespace std;
int n, k, cnt = 0, s, x[500];
void ql(int i, int bd, int sum)
{   
    for(int j = bd; j <= n; j++){
        x[i] = j;
        if(i == k){
            if(sum + j == s) cnt++;
        }
        else ql(i+1, j+1, sum+j);
    }
}
int main()
{
    cin >> n >> k >> s;
    ql(1, 1, 0);
    cout << cnt;
}