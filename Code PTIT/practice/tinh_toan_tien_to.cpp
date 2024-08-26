#include <bits/stdc++.h>
using namespace std;

int solve(string s) {
    stack<int> st;
    for(int i = s.length()-1; i >= 0; i--) {
        if(isdigit(s[i])) st.push(s[i]-'0');
        else {
            int o1 = st.top(); st.pop();
            int o2 = st.top(); st.pop();
            int res;
            if(s[i] == '+') res = o1 + o2;
            if(s[i] == '-') res = o1 - o2;
            if(s[i] == '*') res = o1 * o2;
            if(s[i] == '/') res = o1 / o2;
            st.push(res);
        } 
    }
    return st.top();
}
int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << solve(s) << endl;
    }
}