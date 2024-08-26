// #include<iostream>
// #include<queue>
// #define MAX 100
// using namespace std;
// class graph{
//   private:
//     int n, A[MAX][MAX], chuaxet[MAX];
//   public:
//     void readdata();
//     void init();
//     void queueBFS(int u);
// };
// void graph::readdata(){
//     cin >> n;
//     for(int i = 1 ;i <= n; i++)
//         for(int j = 1; j <= n; j++) cin >> A[i][j];
// }
// void graph::init(){
//     for(int i = 1; i<=n ; i++) chuaxet[i] = true; 
// }
// void graph::queueBFS(int u){
//     queue<int> q ;
//     q.push(u); chuaxet[u] = false;
//     while(!q.empty()){
//         int a, s = q.front(); q.pop();
//         cout << s << " ";
//         for(int t=1; t <= n; t++){
//             if(A[s][t] == 1 && chuaxet[t] == true){
//                 q.push(t);
//                 chuaxet[t] = false;
//             }
//         }
        
//     }
// }
// int main(){
//     graph g;
//     g.readdata();
//     g.init();
//     g.queueBFS(1);
// }
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
bool check[100];
int a[100][100], n, s;
void BFS_queue(int u)
{
    queue<int> qe;
    qe.push(u);
    check[u] = true;
    cout << u << " ";
    while(!qe.empty())
    {
        int s = qe.front();
        qe.pop();
        for(int v = 1; v <= n; v++)
        {
            if(a[s][v] == 1 && check[v] == false)
            {
                cout << v << " ";
                qe.push(v);
                check[v] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++) cin >> a[i][j];
    }
    memset(check, false, sizeof(check));
    BFS_queue(s);
    return 0;
}