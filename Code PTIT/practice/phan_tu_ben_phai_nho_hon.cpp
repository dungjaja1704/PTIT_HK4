#include <bits/stdc++.h>
using namespace std;

void greater_right(int a[], int n, int GR[]) {
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[i] > a[st.top()]) {
            GR[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        GR[st.top()] = -1;
        st.pop();
    }
}

void smaller_right(int a[], int n, int SR[]) {
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[i] < a[st.top()]) {
            SR[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        SR[st.top()] = -1;
        st.pop();
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n], GR[n], SR[n];
        for(int &x : a) cin >> x;
        greater_right(a, n, GR);
        smaller_right(a, n, SR);
        for(int i = 0; i < n; i++) {
            if(GR[i] != -1 &&  SR[GR[i]] != -1) {
                cout << a[SR[GR[i]]] << " ";
            }
            else cout << -1 << " ";
        }
        cout << endl;
    }
}
