#include<bits/stdc++.h>
using namespace std;
int money[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
int main()
{   
    int t; cin >> t;
    while(t--){
        int n, cnt = 0, index = 0;
        cin >> n;
        while(n)
        {
            cnt += n/money[index];
            n = n % money[index];
            index++;
        }
        cout << cnt << endl;
    }
}
