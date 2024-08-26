#include <bits/stdc++.h>
using namespace std;

int F[101][101];
int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(j == 1 || j == i) F[i][j] = 1;
            else F[i][j] = F[i-1][j-1] + F[i-1][j];
            cout << F[i][j] << " ";
        }
        cout << endl;
    }
}
// int tinh(int i, int j) 
// {
//     if(i == j || j == 1) return 1;
//     if(F[i][j]) return F[i][j];
//     return F[i][j] = tinh(i-1, j) + tinh(i-1, j-1);
// }
// int main()
// {
//     int n; cin >> n;
//     for(int i = 1; i <= n; i++) {
//         for(int j = 1; j <= i; j++) {
//             cout << tinh(i, j) << " ";
//         }
//         cout << endl;
//     }
// }