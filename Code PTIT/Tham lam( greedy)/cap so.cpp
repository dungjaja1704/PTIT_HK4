#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> c, l;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if(x % 2 == 0) c.push_back(x);
        else l.push_back(x);
    }
    if(c.size() % 2 == 0)
    {
        cout << "YES";
    }
    else
    {
        for(int x : c)
        {
            for(int y : l)
            {
                if(abs(x-y) == 1)
                {
                    cout << "YES";
                    return 0;
                }
            }
        }
        cout << "NO";
    }
}