#include <bits/stdc++.h>
using namespace std;
int n;
int parent[1000001];

void ktao()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
}

int find(int u) {
    while(u != parent[u]) {
        u = parent[u];
    }
    return u;
}

bool Union(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) {
        return false;
    }
    else{
        if(u < v) parent[v] = u;
        else parent[u] = v;
    }
}

int main(){
    ktao();
    cout << Union(6, 7) << endl;
    cout << Union(5, 6) << endl;
    cout << Union(4, 5) << endl;
    for(int i = 1; i <= n; i++) {
        cout << i << " " << parent[i] << endl;
    }
}