#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool check[100];
int n, a[100][100];
int DFS(int u){
    stack<int> stk;
    int dem = 1;
    check[u] = false;
    stk.push(u);
    while(!stk.empty()){
        int s=stk.top();
        stk.pop();
        for(int t=1; t<=n; t++){
            if(a[s][t]==1&&check[t]==true){
                dem++;
                check[t]=false;
                stk.push(s);
                stk.push(t);
                break;
            }
        }
    }
    return dem;
}
bool kq(){
    for(int i=1; i<=n; i++){
        if(DFS(i)!=n){
            return false;
        }else{
            memset(check, true,sizeof(check));
        }
    }
    return true;
}
int main(){
    cin >>n;
    memset(check, true, sizeof(check));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
        }
    }
    if(kq()){
        cout << "strongly connected" << endl;
        
    }else{
        cout << "not strongly connected" <<endl;
    }
}