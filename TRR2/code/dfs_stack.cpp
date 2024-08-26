// #include<iostream>
// #include<stack>
// #define MAX 100
// using namespace std;
// class graph
// {
//     private:
//         int A[MAX][MAX], n, chuaxet[MAX];
//     public:
//         void readdata();
//         void init();
//         void recursiveDFS(int u);
//         void stackDFS(int u);
// };
// void graph::readdata()
// {
//     cin >> n; 
//     for(int i = 1; i <= n; i++)
//         for(int j =1; j <= n; j++) cin >> A[i][j];
// }
// void graph::init()
// {
//     for(int i = 1; i <= n; i++) chuaxet[i] = true;
// }
// void graph::recursiveDFS(int u){
//     cout << u << " ";
//     chuaxet[u] = false;
//     for(int v = 1; v <= n; v++)
//         if(A[u][v] == 1 && chuaxet[v] == true) recursiveDFS(v);
// }
// void graph::stackDFS(int u){
//     stack<int> st;
//     cout << u << " ";
//     chuaxet[u] = false;
//     st.push(u);
//     while(!st.empty()){
//         int s = st.top();
//         st.pop();
//         for(int t = 1; t<=n; t++)
//             if((A[s][t] == 1) && (chuaxet[t] == true) ){
//                 cout << t << " ";
//                 chuaxet[t] = false;
//                 st.push(s);
//                 st.push(t);
//                 break;
//             }
//     }
// }
// int main(){
//     graph g;
//     g.readdata(); g.init();
//     g.stackDFS(1); g.recursiveDFS(1);
// }
#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool check[100];
int a[100][100], n;
void DFS_stack(int u)
{
    stack<int> st;
    st.push(u);
    check[u] = true;
    cout << u << " ";
    while(!st.empty())
    {
        int s = st.top();
        st.pop();
        for(int v = 1; v <= n; v++)
        {
            if(a[s][v] == 1 && check[v] == false)
            {
                cout << v << " ";
                st.push(s);
                st.push(v);
                check[v] = true;
                break;
            }
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
    memset(check, false, sizeof(check));
    DFS_stack(1);
    return 0;
}