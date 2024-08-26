// #include<iostream>
// #include<stack>
// #include<queue>
// #define MAX 100
// using namespace std;
// class  graph{
//     int n, A[MAX][MAX]  , chuaxet[MAX], s, t, truoc[MAX];
//     public:
//     void readdata();
//     void init(){
//         for(int i=1;i<=n;i++) { chuaxet[i]=1; truoc[i] = 0;}
//     }
//     void stackdfs(int u);
//     void queuebfs(int u);
//     void pathst();
//     int gets(){return s;}
//     int truoct(){return truoc[t];}
// };
// void graph::readdata(){
//     cin >> n >> s >> t;
//     for(int i=1; i<=n; i++)
//         for(int j=1; j<=n;j++) cin >> A[i][j];
// }
// void graph::stackdfs(int u){
//     stack<int> nganxep;
//     nganxep.push(u);
//     chuaxet[u] = 0;
//     while(!nganxep.empty()){
//         int s = nganxep.top();
//         nganxep.pop();
//         for(int t = 1; t<=n; t++){
//             if(A[s][t] == 1 && chuaxet[t] == 1){
//                 nganxep.push(s); nganxep.push(t); chuaxet[t]=0; truoc[t]=s; break;
//             }
//         }
//     }
// }
// void graph::queuebfs(int u){
//     queue<int> hangdoi;
//     hangdoi.push(u); chuaxet[u] = 0;
//     while(!hangdoi.empty()){
//         int s = hangdoi.front(); hangdoi.pop();
//         for(int t = 1; t <=n; t++)
//             if(A[s][t] == 1 && chuaxet[t] == 1){
//                 hangdoi.push(t); chuaxet[t]= 0; truoc[t] = s;
//             }
//     }
// }
// void graph::pathst(){
//     if(truoc[t]==0) cout << "no path";
//     else{
//         cout << t << " "; int u = truoc[t];
//         while(u!=s){
//             cout << u << " "; 
//             u=truoc[u];
//         }
//         cout << s << "\n";
//     }
// }
// int main(){
//     graph g;
//     g.readdata(); g.init();
//     g.stackdfs(g.gets());
//     if(g.truoct()!=0) {cout << "DFS path: "; g.pathst(); 
//         g.init();
//         g.queuebfs(g.gets());
//         cout << "BFS path: "; g.pathst();
//     }
//     else cout << "no path\n";
// }
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
int n, check[100]={}, a[100][100], s, t;
vector<int> dfs, bfs;
void DFS()
{
    stack<int> st;
    st.push(s);
    check[s] = 1;
    int truoc[100] = {};
    while(!st.empty())
    {
        int i = st.top();
        st.pop();
        for(int j = 1; j <= n; j++)
        {
            if(!check[j] && a[i][j])
            {
                check[j] = 1;
                st.push(i);
                st.push(j);
                truoc[j] = i;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        check[i] = 0;
    }
    if(truoc[t] == 0)
    {
        cout << "no path";
        return;
    }
    cout << "DFS path:";
    dfs.push_back(t);
    while(dfs[dfs.size()-1] != s)
    {
        dfs.push_back(truoc[dfs[dfs.size()-1]]);
    }
    for(int i = 0; i < dfs.size(); i++)
    {
        cout << " " << dfs[i];
    }
    cout << endl;
}
void BFS()
{
    queue<int> qe;
    qe.push(s);
    check[s] = 1;
    int truoc[100] = {};
    while(!qe.empty())
    {
        int i = qe.front();
        qe.pop();
        for(int j = 1; j <= n; j++)
        {
            if(!check[j] && a[i][j])
            {
                check[j] = 1;
                qe.push(j);
                truoc[j] = i;
            }
        }
    }
    if(truoc[t] == 0) return;
    cout << "BFS path:";
    bfs.push_back(t);
    while(bfs[bfs.size()-1] != s)
    {
        bfs.push_back(truoc[bfs[bfs.size()-1]]);
    }
    for(int i = 0; i < bfs.size(); i++)
    {
        cout << " " << bfs[i];
    }
    cout << endl;
}
int main()
{
    cin >> n >> s >> t;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    DFS();
    BFS();
}