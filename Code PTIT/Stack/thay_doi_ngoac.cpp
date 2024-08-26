#include <bits/stdc++.h>
using namespace std;

void replace (string s) {
    int n = s.size();
    vector<int> pos(n, -1);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            st.push(i);
        }
        else if (s[i] == ')'){
            if(!st.empty()) {
                pos[i] = 1;
                pos[st.top()] = 0;
                st.pop();
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(s[i] == '(' || s[i] == ')') {
            cout << pos[i];
        }
        else cout << s[i];
    }
    cout << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        replace(s);
    }
}