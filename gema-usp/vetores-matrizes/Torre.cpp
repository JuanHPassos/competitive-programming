#include <bits/stdc++.h>
using namespace std;
int m[1010][1010];
int main(){
    int sl[1010];
    int sc[1010];
    for(int i = 0; i<1010; i++){
        sl[i] = 0;
        sc[i] = 0;}
    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++){
            cin >> m[i][j];
            sl[i] += m[i][j];
            sc[j] += m[i][j];}
    int resp = -1, soma;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++){
            soma = sl[i]+sc[j]-2*m[i][j];
        if (soma > resp)
            resp = soma;
        }    
    cout << resp << '\n';
}