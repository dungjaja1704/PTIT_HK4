#include <bits/stdc++.h>
using namespace std;

string xuly(string s) {
    stack<int> st;
    for(int i = 0; i < s.length(); i++) {
        if(!st.empty() && s[i] == st.top()) {
            st.pop();
        }
        else st.push(s[i]);
    }
    string res = "";
    while(!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}
int main() {
    string s; cin >> s;
    string res = xuly(s);
    if(res == "") cout << "EMPTY";
    else cout << res;
}