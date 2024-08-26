#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll process(ll n, char p, char q)
{
    string s = to_string(n);
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == p){
            s[i] = q;
        }
    }
    return stoll(s);
}
int main()
{
    ll a, b;
    cin >> a >> b;
    cout << process(a, '6', '5') + process(b, '6', '5') << " ";
    cout << process(a, '5', '6') + process(b, '5', '6');
}