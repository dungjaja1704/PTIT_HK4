#include <bits/stdc++.h>
using namespace std;

int n, k, a[100], x[100], ok;
void in() {
    for(int i = 1; i <= k; i++) 
        cout << char(x[i] + 'A' - 1);
    cout << endl; 
}
void ql(int i) {
    for(int j = 1; j <= n; j++) {
        x[i] = j;
        if(i == k) in();
        else ql(i+1);
    }
}

int main() {
    char c;
    cin >> c >> k;
    n = c - 'A' + 1;
    ql(1);
}