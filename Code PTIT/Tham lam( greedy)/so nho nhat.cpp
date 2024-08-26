#include<bits/stdc++.h>
using namespace std;
string beNhat(int sum, int n)
{   
    string res = string(n, '0');
    for(int i = n - 1; i >= 0; i--)
    {
        if(sum > 9)
        {
            res[i] = '9';
            sum -= 9;
        }
        else{
            if(i != 0)
            {
                res[0] = '1';
                res[i] += sum - 1;
                return res;
            }
            else
            {
                res[i] += sum;
                return res; 
            }
        }
    }
    return res;
}
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int sum, n;
        cin >> sum >> n;
        if(n * 9 < sum || (n > 1 && sum == 0))
        {
            cout << -1 << endl;
        }
        else cout << beNhat(sum, n) << endl;
    }
}