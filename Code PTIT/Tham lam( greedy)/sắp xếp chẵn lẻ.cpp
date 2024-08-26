#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, i1 = 0, i2 = 0;
    cin >> n;
    int a[n];
    vector<int> chan, le;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(i % 2 == 0)
        {
            le.push_back(a[i]);
    	}
        else
        {
       		chan.push_back(a[i]);
        }
    }
    sort(le.begin(), le.end());
    sort(chan.begin(), chan.end(), greater<int>());
    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            cout << le[i1++] << " ";
        }
	    else
    	{
            cout << chan[i2++] << " ";
        }   
    }
}

