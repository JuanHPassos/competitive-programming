#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n, x, tam = 0, resp = -1;
    cin >> n;
    int v[n], pont[n];
    for(int i = 0; i<n; i++){
        cin >> v[i];
        pont[i] = 0;}
    x = v[0];
    for(int i = 1; i<=n; i++){
        pont[tam]++;
        if(x != v[i]){
            tam++;
            x = v[i];
        }
    }
    for(int i = 0; i< tam; i++){
        if(resp < pont[i]){
            resp = pont[i];}
    }
    cout << resp << '\n';
    return 0;
}

