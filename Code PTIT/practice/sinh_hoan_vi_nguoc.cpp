#include <bits/stdc++.h>
using namespace std;

int n, a[100], x[100], ok;

bool used[1005];
void ql(int i) {
    for(int j = n; j >= 1; j--) {
        if(!used[j]) {
            x[i] = j;
            used[j] = true;
            if(i == n) {
                for(int u = 1; u <= n; u++) {
                    cout << a[x[u]] << " ";
                }
                cout << endl;
            }
            else ql(i+1);
            used[j] = false;
        }
    }
}

int main() {
    int m; cin >> m;
    set<int> se;
    for(int i = 1; i <= m; i++) {
        int x; cin >> x;
        se.insert(x);
    }
    n = 0;
    for(int x : se) {
        n++;
        a[n] = x;
    }
    ql(1);
}