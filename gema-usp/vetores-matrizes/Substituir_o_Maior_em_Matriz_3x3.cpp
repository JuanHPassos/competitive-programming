#include <bits/stdc++.h>
using namespace std;
int main(){
    int matriz[3][3], maior;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cin >> matriz[i][j];
            if( i == 0 && j == 0)
                maior = matriz[0][0];
            if(matriz[i][j] > maior)
                maior = matriz[i][j];
        }
    }
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(matriz[i][j] == maior)
                cout << -1 << " ";
            else
                cout << matriz[i][j] << " ";
        }
    cout << '\n';
    }
    return 0;
}
            