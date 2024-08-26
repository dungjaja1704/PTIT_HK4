#include<bits/stdc++.h>
using namespace std;
int xuly(string s)
{
    stack<int> st;
    int res = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '[') st.push(i);
        else
        {   
            if(st.empty()) res+=2;
            else{ 
                st.pop();
            }
        }
    }
    return res + st.size() / 2;
}
int main()
{
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        cout << xuly(s) << endl;
    }
}