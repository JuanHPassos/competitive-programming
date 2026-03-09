#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
int n;
vector<int> pai(MAXN);
vector<int> tam(MAXN);

void init(){
    for(int i = 1; i<=n; i++){
        pai[i] = i; tam[i] = 1;
    }
}

int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(tam[a] > tam[b]){
        pai[b] = a;
        tam[a] += tam[b];
    }
    else{
        pai[a] = b;
        tam[b] += tam[a];
    }
}

int main(){
    int k;
    cin >> n >> k;
    init();
    for(int i = 0 ;i<k; i++){
        char op; int a, b;
        cin >> op >> a >> b;
        if(op == 'C'){
            if(find(a) == find(b)) cout << "S\n";
            else cout << "N\n";
        }
        else{
            merge(a,b);
        }
        
    }

}