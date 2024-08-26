#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll F[100];
void init()
{
    F[1] = 1; F[2] = 1;
    for(int i = 3; i <= 92; i++)
    {
        F[i] = F[i-1] + F[i-2];
    }
}
char fibonacci(int n, ll k)
{
    if(n == 1) return 'A';
    if(n == 2) return 'B';
    if(k <= F[n-2])
    {
        return fibonacci(n-2, k);
    } 
    else
    {
        return fibonacci(n-1, k-F[n-2]);
    }
}
int main()
{   
    int t; cin >> t;
    while(t--){
        init();
        ll n, k; cin >> n >> k;
        cout << fibonacci(n, k) << endl;
    }
}
