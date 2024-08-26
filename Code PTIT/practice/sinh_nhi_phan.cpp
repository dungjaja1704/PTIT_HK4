#include <bits/stdc++.h>
using namespace std;

int n, k, ok, x[100];
void init() {
    for(int i = 1; i <= n; i++) {
        x[i] = 0;
    }
}
void sinh() {
    int i = n;
    while(i >= 1 && x[i] == 1) {
        x[i] = 0;
        i--;
    }
    if(i == 0) ok = 0;
    else x[i] = 1;
}
int main() {
    cin >> n;
    ok = 1;
    init();
    while(ok) {
        for(int i = 1; i <= n; i++) {
            cout << x[i];
        }
        cout << endl;
        sinh();
    }
}