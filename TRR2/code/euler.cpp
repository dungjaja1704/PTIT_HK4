#include<iostream>
#include<stack>
#define MAX 100
using namespace std;
class graph{
    private:
       int n, A[MAX][MAX], s;
    public:
       void readdata(){
           cin >> n >> s;
           for(int i=1; i <= n; i++)
               for(int j=1; j <= n; j++) cin >> A[i][j];
       }
       void euler(int s){
           stack<int> stk, CE;
           stk.push(s);
           while(!stk.empty()){
              int t = stk.top() , isolated = 1;
              for(int k=1; k<=n; k++)
                  if(A[t][k]==1){
                      isolated = 0;
                      stk.push(k);
                      A[t][k] = A[k][t] = 0;
                      break;
                  }
                  if(isolated == 1){
                      stk.pop();
                      CE.push(t);
                  }
              }
           while(!CE.empty()){
                cout << CE.top() << " ";
                CE.pop();
           }
       }
       int gets(){ return s;}
};
int main(){
    graph g;
    g.readdata(); g.euler(g.gets());
}