#include <bits/stdc++.h>
using namespace std;

int n, a[100], x[100], ok;

void init() {
    for(int i = 1; i <= n; i++) {
        x[i] = 6;
    }
}

void sinh() {
    int i = n; 
    while(i >= 1 && x[i] == 8) {
        x[i] = 6;
        i--;
    }
    if(i == 0) ok = 0;
    else x[i] = 8;
}

int main() {
    int k; cin >> k;
    vector<string> v;
    for(n = 1; v.size() < k; n++) {
        init();
        ok = 1;
        while(ok && v.size() < k) {
            string s = "";
            for(int i = 1; i <= n; i++) {
                s += to_string(x[i]);
            }
            for(int i = n; i >= 1; i--) {
                s += to_string(x[i]);
            }
            v.push_back(s);
            sinh();
        }
    }
    for(string x : v) cout << x << " ";
}