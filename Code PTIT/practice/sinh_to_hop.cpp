#include <bits/stdc++.h>
using namespace std;

int n, k, x[100], ok;

void init() {
    for(int i = 1; i <= k; i++) {
        x[i] = i;
    }
}

void sinh() {
    int i = k;
    while(i >= 1 && x[i] == n - k + i) {
        --i;
    }
    if(i == 0) ok = 0;
    else {
        x[i]++;
        for(int j = i + 1; j <= k; j++) {
            x[j] = x[j - 1] + 1;
        }
    }
}

int main() {
    cin >> n >> k;
    ok = 1;
    init();
    while(ok) {
        for(int i = 1; i <= k; i++) {
            cout << x[i];
        }
        cout << endl;
        sinh();
    }
}