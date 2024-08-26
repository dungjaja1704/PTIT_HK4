#include<bits/stdc++.h>
using namespace std;
int n, s, cnt = 0, a[500], x[500];
void ql(int i, int bd, int sum)
{
    for(int j = bd; j <= n; j++){
        x[i] = a[j];
        if(sum + a[j] == s){
            cout << "[";
            for(int u = 1; u <= i; u++){
                cout << x[u];
                if(u < i) cout << " ";
            }
            cout << "]";
            cout << endl;
        }
        else if(sum + a[j] < s){
            ql(i+1, j+1, sum+a[j]);
        }
    }
}
int main(){
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    ql(1, 1, 0);
}