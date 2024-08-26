#include <bits/stdc++.h>
using namespace std;
vector<int> res;

void solve() {
    queue<string> q;
    q.push("6");
    q.push("8");
    while(true) {
        string tmp = q.front();
        q.pop();
        if(tmp.size() == 19) break;
        q.push(tmp + "6");
        q.push(tmp + "8");
    }
}

int main() {
    solve();
    for(int x : res){
        cout << x << endl;
    }
}