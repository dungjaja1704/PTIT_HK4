#include <bits/stdc++.h>
using namespace std;

int n, x[100];

void init() {
    for(int i = 1; i <= n; i++) {
        x[i] = i;
    } 
}

int main() {
    cin >> n;
    init();
    do {
        for(int i = 1; i <= n; i++) {
            cout << x[i];
        }
        cout << endl;
    }while(next_permutation(x + 1, x + n + 1));
}
