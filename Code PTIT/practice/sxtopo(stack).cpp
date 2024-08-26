#include <bits/stdc++.h>
using namespace std;

bool used[1005];
vector<int> adj[1005];
int n, m;
stack<int> st;
void dfs(int u) {
    used[u] = true;
    for(int v : adj[u]) {
        if(!used[v]) {
            dfs(v);
        }
    }
    st.push(u);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    for(int i = 1; i <= n; i++) {
        if(!used[i]) dfs(i);
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}