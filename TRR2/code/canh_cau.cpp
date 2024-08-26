#include<iostream>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
int n, check[100], kq=0, a[100][100], b[100][100];
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> a[i][j];
            b[i][j]=a[i][j];
        }
    }
    int dem = 0;
    for(int i=1; i<=n; i++){
        if(check[i]==0){
            dem++;
            queue<int> q;
            q.push(i);
            check[i]=1;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int j=1; j<=n; j++){
                    if(a[u][j]==1 && check[j]==0){
                        check[j] = 1;
                        q.push(j);
                    }
                }
            }
        }    
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n ; j++){
            if(a[i][j] == 1){
                a[i][j]=0;
                memset(check, 0, sizeof(check));
                int dem1 = 0;
                for(int i=1; i<=n; i++){
                    if(check[i]==0){
                        dem1++;
                        queue<int> q;
                        q.push(i);
                        check[i]=1;
                        while(!q.empty()){
                            int u = q.front();
                            q.pop();
                            for(int j=1; j<=n; j++){
                                if(a[u][j] == 1 && check[j]==0){
                                    check[j] = 1;
                                    q.push(j);
                                }
                            }
                        }
                    }
                }
                if(dem1>dem){
                    cout << i << " " << j << endl;
                }
                a[i][j] = 1;
            }
        }
    }
}