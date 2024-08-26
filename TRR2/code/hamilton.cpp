// #include<iostream>
// #define MAX 100
// using namespace std;
// class Graph{
//     private:
//         int n, s, A[MAX][MAX], chuaxet[MAX], X[MAX];
//     public:
//         void readdata(){
//             cin >> n >> s;
//             for(int i=1; i<=n; i++)
//                 for(int j=1; j<=n; j++) cin >> A[i][j];
//         }
//         void init(){
//             for(int i=1; i<=n; i++) chuaxet[i] = 1;
//             X[1] = s; chuaxet[X[1]] = 0;
//         }
//         void hmt(int k){
//             for(int y=1; y<=n; y++)
//                 if(A[X[k-1]][y] == 1)
//                     if((k==n+1) && (y==s)){
//                         for(int i=1; i<=n; i++) cout << X[i] << " ";
//                         cout << y << endl;
//                     }
//                     else 
//                         if(chuaxet[y] == 1){
//                             X[k] = y;
//                             chuaxet[y] = 0;
//                             hmt(k+1);
//                             chuaxet[y] = 1;
//                         }
//         }
// };
// int main(){
//     Graph g;
//     g.readdata();
//     g.init(); g.hmt(2);
// }
#include<iostream>
using namespace std;
int a[100][100], x[100], n, u, d;
bool chuaxet[100];
void init()
{
    cin >> n >> u;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
}
void tao()
{
    for(int i = 1; i <= n; i++)
    {
        chuaxet[i] = true;
    }
}
void hmt(int k)
{
    for(int i = 1; i <= n; i++)
    {
        if(a[x[k - 1]][i])
        {
            if(k == n + 1 && i == u)
            {
                for(int j = 1; j <= n; j++)
                {
                    cout << x[j] << " ";
                }
                cout << x[1] << endl;
            }
            else
            {
                if(chuaxet[i])
                {
                    x[k] = i;
                    chuaxet[i] = false;
                    hmt(k + 1);
                    chuaxet[i] = true;
                }
            }
        }
    }
}
int main()
{
    init();
    tao();
    x[1] = u;
    chuaxet[u] = false;
    hmt(2);
    return 0;
}