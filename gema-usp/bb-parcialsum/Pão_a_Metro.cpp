#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int n, k;
vector<int> m(MAXN);
int pos(int med){
    int soma = 0;
    for(int i = 0; i<k; i++){
        soma += m[i]/med;
    }
    if(soma > n-1) return 1;
    else return 0;
}

int main(){
    int r, l, maior = -1;
    cin >> n >> k;
    for(int i  = 0; i<k; i++){
        cin >> m[i];
        maior = max(maior, m[i]);
    }
    l = 1;
    r = maior;
    while(l<r){
        int med = (l+r)/2;
        if(pos(med)) l = med+1;
        else r = med; 
    }
    r--;
    cout << r;
    return 0;
}