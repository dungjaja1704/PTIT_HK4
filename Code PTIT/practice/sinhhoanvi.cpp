#include <bits/stdc++.h>
using namespace std;
int n, k, x[100], ok;
void init() {
    for(int i = 1; i <= n; i++) {
        x[i] = i;
    }
}
 
void sinh() {
    int i = n;
    while(i >= 1 && x[i] > x[i+1]) {
        i--;
    }
    if(i == 0) ok = 0;
    else {
        int j = n;
        while(x[j] < x[i]) {
            j--;
        }
        swap(x[i], x[j]);
        reverse(x+i+1, x+1+n);
    }
} 
int main() {
    cin >> n;
    ok = 1;
    init();
    while(ok) {
        for(int i = 1; i <= n; i++) {
            cout << x[i] << " ";
        }
        cout << endl;
        sinh();
    }
}