#include<iostream>
#include<algorithm>
#define MAX 100
using namespace std;
struct  Edge{   int     s, e, w;    };   //s: edge start; e: edge end;   w: edge weight
class   Graph{
    private:
        int     n, s, A[MAX][MAX], chuaxet[MAX], T[MAX][MAX], ne, dH;
        Edge    eArr[MAX];
    public:
        void    readdata();
        void    init();
        void    T_DFS(int u);
        void    Kruskal();
        void    Prim(int s);
        int     getS(){ return s;   }
};
void    Graph::readdata(){
    cin>>n>>s;
    ne=0;
    for(int i=1; i<=n; i++){
        chuaxet[i]=1;
        for(int j=1; j<=n; j++){
            T[i][j]=0;
            cin>>A[i][j];
            if((A[i][j]!=0)&&(i<j)){
                ne++;
                eArr[ne].s=i;   eArr[ne].e=j;   eArr[ne].w=A[i][j];
            }
        }
    }
}
void    Graph::init(){
    for(int i=1; i<=n; i++) chuaxet[i]=1;
}
void    Graph::T_DFS(int u){
    chuaxet[u]=0;
    for(int v=1; v<=n; v++)
        if((T[u][v]==1)&&(chuaxet[v]==1))   T_DFS(v);
}
bool    eCompare(Edge e1, Edge e2){
    if(e1.w==e2.w)
        if(e1.s==e2.s)
            return  e1.e<e2.e;
        else
            return  e1.s<e2.s;
    return e1.w<e2.w;
}
void    Graph::Kruskal(){
    dH=0;
    int neT=0;
    Edge    eArr_T[MAX];
    sort(eArr+1, eArr+ne+1, eCompare);
    for(int e=1; e<=ne; e++){
        init(); T_DFS(eArr[e].s);
        if(chuaxet[eArr[e].e]==1){
            neT++;
            eArr_T[neT].s=eArr[e].s;    eArr_T[neT].e=eArr[e].e;    dH+=eArr[e].w;
            T[eArr[e].s][eArr[e].e]=T[eArr[e].e][eArr[e].s]=1;
        }
    }
    cout<<"dH = "<<dH<<endl;
    for(int e=1; e<=neT; e++)   cout<<eArr_T[e].s<<" "<<eArr_T[e].e<<endl;
}
void    Graph::Prim(int s){
    dH=0;
    int neT=0;
    Edge    eArr_T[MAX];
    sort(eArr+1, eArr+ne+1, eCompare);
    for(int eT=1; eT<=n-1; eT++){
        init(); T_DFS(s);
        bool foundEdge = false;
        for(int e=1; e<=ne; e++){
            if(chuaxet[eArr[e].s]+chuaxet[eArr[e].e]==1){
                neT++;
                eArr_T[neT].s=eArr[e].s;    eArr_T[neT].e=eArr[e].e;    dH+=eArr[e].w;
                T[eArr[e].s][eArr[e].e]=T[eArr[e].e][eArr[e].s]=1;
                foundEdge = true;
                break;
            }
        }
        if (!foundEdge) {
            cout << "No spanning tree" << endl;
            return;
        }
    }
    cout<<"d(T) = "<<dH<<endl;
    for(int e=1; e<=neT; e++)   cout<<eArr_T[e].s<<" "<<eArr_T[e].e<<endl;
}
int main(){
    Graph   g;
    g.readdata();   g.Prim(g.getS());   //g.Kruskal();
}