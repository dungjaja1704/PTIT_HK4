// #include<iostream>
// #define MAX 100
// using namespace std;
// class graph
// {
//   private:
//     int A[MAX][MAX], n, chuaxet[MAX];
//   public:
//     void readdata();
//     void init();
//     void recursiveDFS(int u);
// };
// void graph::readdata()
// {
//     cin >> n;
//     for(int i=1; i<=n ; i++)
//     {
//         for(int j = 1; j <= n ; j++) cin >> A[i][j]; 
//     }
// }
// void graph::init()
// {
//     for(int i = 1; i <= n; i++) chuaxet[i] = true;
// }
// void graph::recursiveDFS(int u)
// {
//     cout << u <<" ";
//     chuaxet[u] = false;
//     for(int v= 1; v<= n; v++)
//     {
//         if(A[u][v] == 1 && (chuaxet[v] == true)) recursiveDFS(v);
//     }
// }
// int main()
// {
//     graph g;
//     g.readdata(); g.init();g.recursiveDFS(1);
// }
#include<iostream>
using namespace std;
bool check[1000];
int n;
int a[1000][1000];
void DFS(int u)
{
    cout << u << " ";
    check[u] = true;
    for(int v = 1; v <= n; v++)
    {
        if(a[u][v] == 1 && check[v] == false)
        {
            DFS(v);
        }
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    DFS(2);
    return 0;
}
