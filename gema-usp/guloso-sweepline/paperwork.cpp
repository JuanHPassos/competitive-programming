#include<bits/stdc++.h>
using namespace std;
const int MAXN = 110;
vector<int> dias(MAXN);
vector<int> pastas(MAXN, 0);
int n, a;
 
int main(){
    cin >> n;
    int cont = 0, tam = 0;
    for(int i = 0; i<n; i++){
        cin >> a;
        if(a < 0) cont++;
        if(cont == 3){
            tam++;
            cont = 1;
        }
        pastas[tam]++;
    }
    cout << tam+1<< endl;
    for(int i = 0; i <= tam; i++){
        cout << pastas[i] << " ";
    }
    return 0;
}
