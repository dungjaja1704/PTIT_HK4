#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    cin.ignore(); // ignore the newline character after t
    while(t--) {
        string s;
        getline(cin, s); // use getline to read the whole line
        stack<string> st;
        stringstream ss(s);
        string word;
        while(ss >> word) {
            st.push(word);
        }
        while(!st.empty()) {
            cout << st.top();
            st.pop();
            if(!st.empty()) cout << " "; // add a space between words
        }
        cout << "\n";
    }
}