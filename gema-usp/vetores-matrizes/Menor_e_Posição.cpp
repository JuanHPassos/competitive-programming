#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, menor_valor, posicao = 0;
    cin >> N;
    int vet[N];
    for(int i = 0; i<N; i++){
        cin >> vet[i];
        if( i ==0 )
            menor_valor = vet[0];
        if(vet[i] < menor_valor){
            menor_valor = vet[i];
            posicao = i;
        }
    }
    cout << "Menor valor: " << menor_valor << '\n';
    cout << "Posicao: " << posicao << '\n';
    return 0;
}