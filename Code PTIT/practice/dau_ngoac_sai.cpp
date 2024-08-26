#include <bits/stdc++.h>
using namespace std;

int xuly(string s) {
    stack<int> st;
    int cnt = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            st.push(i);
        }
        else {
            if(!st.empty()) {
                st.pop();
            }
            else cnt++;
        }
    }
    cnt += st.size();
    return cnt;
}

int main() {
    string s;
    cin >> s;
    scanf("\n");
    cout << xuly(s);
}