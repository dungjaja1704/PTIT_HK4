#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int sum; 
        cin >> sum;
        int d4 = -1, d7;
        for(d7 = sum/7; d7 >= 0; d7--)
        {
            if((sum - d7 * 7) % 4 == 0)
            {
                d4 = (sum - d7 * 7) / 4;
                break;
            }
        }
        if(d4 != -1){
            for(int i = 0; i < d4; i++)
            {
                cout << 4;
            }
            for(int i = 0; i < d7; i++)
            {
                cout << 7;
            }
            cout << endl;
        }
        else cout << -1 << endl;
    }
}