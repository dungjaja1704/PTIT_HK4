#include <bits/stdc++.h>
using namespace std;
#define ll long long
void smaller_left(int a[], int n, int L[]) {
    stack<int> st;
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && a[i] < a[st.top()]) {
            L[st.top()] = i;
            st.pop(); 
        }
        st.push(i);
    }
    while(!st.empty()) {
        L[st.top()] = -1;
        st.pop();
    }
}

void smaller_right(int a[], int n, int R[]) {
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[i] < a[st.top()]) {
            R[st.top()] = i;
            st.pop(); 
        }
        st.push(i);
    }
    while(!st.empty()) {
        R[st.top()] = n;
        st.pop();
    }
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n], L[n], R[n];
        for(int &x : a) cin >> x;
        smaller_left(a, n, L);
        smaller_right(a, n, R);
        long long res = 0;
        for(int i = 0; i < n; i++) {
            int w = R[i] - L[i] - 1;
            long long dt = 1ll * w * a[i];
            res = max(dt, res);
        }
        cout << res << endl;
    }
}
