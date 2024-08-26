#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ke[100001], t_ke[100001];
bool visited[100001];
stack<int> st;

void nhap() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        ke[x].push_back(y);
        t_ke[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

void DFS1(int u) {
    visited[u] = true;
    for(int v : ke[u]) {
        if(!visited[v]){
            DFS1(v);
        }
    }
    st.push(u);
}

void DFS2(int u) {
    // cout << u << " ";
    visited[u] = true;
    for(int v : t_ke[u]){
        if(!visited[v]) {
            DFS2(v);
        }
    }
} 

void kosaraju() {
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            DFS1(i);
        }
    }
    memset(visited, false, sizeof(visited));
    int scc = 0;
    while(!st.empty()) {
        int top = st.top(); st.pop();
        if(!visited[top]) {
            ++scc;
            DFS2(top);
            cout << endl;
        }
    }
    if(scc == 1) cout << "YES";
    else cout << "NO";
}
int main() {
    nhap();
    kosaraju();
}