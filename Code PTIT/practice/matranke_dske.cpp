#include <bits/stdc++.h>
using namespace std;

void test() {
    int n, x; cin >> n;
    vector<vector<int>> e(n+1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> x;
            if(x == 1) e[i].push_back(j);
        }
    }
    for (int i = 1; i <= n; i++) {
        for(int j : e[i]) cout << j << " ";
        cout << endl;
    }
}
int main() {
    int t = 1;
    while(t--){
        test();
        cout << "\n";
    }
}