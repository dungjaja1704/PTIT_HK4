#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void solve(string s) {
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--) {
        if(isalpha(s[i])){
            st.push(string(1, s[i]));
        }
        else {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string tmp = "(" + op1 + s[i] + op2 + ")";
            st.push(tmp);
        }
    }
    cout << st.top() << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        string s;
        cin >> s;
        solve(s);
    }   
}