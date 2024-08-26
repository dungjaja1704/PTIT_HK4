#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, s, m; cin >> n >> s >> m;
        int song = s * m;
        int soNgayDiCho = s - s/7;
        int tongDiCho = n * soNgayDiCho;
        if(song > tongDiCho) 
            cout << -1 << endl;
        else{
            for(int i = 1; i <= soNgayDiCho; i++)
            {
                if(i * n >= song)
                {
                    cout << i << endl;;
                    break;
                }
            }
        }
    }
}