#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s; cin >> s;
    int d[256] = {0};
    for(char c : s) d[c]++;
    int so_luong_tan_suat_le = 0;
    for(int i = 0; i < 256; i++)
    {
        if(d[i] % 2 == 1) so_luong_tan_suat_le++;
    }
    if(so_luong_tan_suat_le == 0 || so_luong_tan_suat_le % 2 == 1)
    {
        cout << 1;
    }
    else cout << 2;
}