#include<bits/stdc++.h>
using namespace std;
void ktSinh(){

}
void sinhHoanVi(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) a[i] = i+1;
    do{
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << endl;
    }while(next_permutation(a, a+n));
}