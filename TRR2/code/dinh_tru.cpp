#include<iostream>
#define MAX 100
using namespace std;
class graph{
    int n , A[MAX][MAX], chuaxet[MAX];
    public:
    void readdata();
    void reinit(){
        for(int i = 1; i<=n; i++) chuaxet[i] = 1;
    }
    void dfs(int u){
        chuaxet[u]=0;
        for(int v=1; v<=n; v++)
            if(A[u][v] == 1 && chuaxet[v] == 1) dfs(v);
    }
    void dinhtru();
};
void graph::readdata(){
    cin >> n;
    for(int i = 1; i<=n; i++)
        for(int j=1; j<=n; j++) cin >> A[i][j];
}
void graph::dinhtru(){
    reinit();
    for(int u=1; u <= n; u++){
        chuaxet[u] = 0;
        if(u==1) dfs(2);
        else dfs(1);
        int tru = 0;
        for(int i=1;i<=n; i++)
            if(chuaxet[i] == 1){
                tru = 1;
                break;
            }
            if(tru==1) cout <<u<<" ";
            reinit();
    }
}
int main(){
    graph g;
    g.readdata();
    g.dinhtru();
}