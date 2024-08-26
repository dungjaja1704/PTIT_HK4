#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, x[100], cnt = 0, cot[100], xuoi[100], nguoc[100];
void Try(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(cot[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j -1] == 0)
        {
            x[i] = j;
            cot[j] = 1; xuoi[i - j + n] = 1; nguoc[i + j - 1] = 1;
            if(i == n)
            {
                for(int i = 1; i <= n; i++)
                {
                    cout << i << " "<< x[i] << " ";
                }
                cout << endl;
            }
            else 
            {
                Try(i + 1);
            }
        cot[j] = 0; xuoi[i - j + n] = 0; nguoc[i + j - 1] = 0;
        }
    }
}
int main()
{
    cin >> n;
    Try(1);
}