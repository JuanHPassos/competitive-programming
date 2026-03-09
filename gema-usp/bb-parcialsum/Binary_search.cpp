#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, x;
    cin >> n >> q;
    vector<int> vet(n);
    map<int, int> busca;
    for(int i = 0; i<n; i++){
        cin >> vet[i];
        if(busca.find(vet[i]) == busca.end()){
            busca[vet[i]] = i;
        }
    }
    for(int i = 0; i<q; i++){
        cin >> x;
        if(busca.find(x) != busca.end())
            cout << busca[x];
        else
            cout << -1;
        cout << '\n';
    }
    return 0;
}