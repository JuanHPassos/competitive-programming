#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+2;

long long int tree[4*MAXN];
int v[MAXN];

void atualiza(int no, int l, int r, int id, int v){
    if(l == r){
        tree[no] = v;
        return;
    }

    int mid = (l+r)/2;

    if(id <= mid) atualiza(2*no, l, mid, id, v);
    else atualiza(2*no + 1, mid+1, r, id, v);

    tree[no] = tree[2*no] + tree[2*no + 1];

}

long long int consulta(int no, int l, int r, int p, int q){
    if(l > q || r < p) return 0;
    
    if(p <= l && q >= r) return tree[no];

    int mid = (l+r)/2;

    return consulta(2*no, l, mid, p, q) + consulta(2*no + 1, mid + 1, r, p, q);
}

void build(int no, int l, int r){
    if(l == r){
        tree[no] = v[l];
        return;
    }

    int mid = (l+r)/2;

    build(2*no, l, mid);
    build(2*no + 1, mid + 1, r);

    tree[no] = tree[2*no] + tree[2*no + 1];
}

int main(){
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    build(1, 1, n);
    for(int i = 0; i < q; i++){
        int a, b, c;
        cin >> a >> b >> c;
        b++; // Ajustar para 1 indexido
        if(a == 1){
            atualiza(1, 1, n, b, c);
        }
        else{
            long long int ans = consulta(1, 1, n, b, c);
            cout << ans << endl; 
        }
    }
}
