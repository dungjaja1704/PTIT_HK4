#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], b[n];
        for(int &x : a) cin >> x;
        for(int &x : b) cin >> x;
        sort(a, a+n, greater<int>());
        sort(b, b+n);
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += (long long) a[i] * b[i]; 
        }
        cout << sum << endl;
    }
}
