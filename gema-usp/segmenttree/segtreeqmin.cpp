#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
const int INF = 1e9+2;

typedef struct tree{
    int min;
    int qmin;
}TREE;

TREE tree[4*MAXN];
int v[MAXN];

void build(int node, int l, int r){
    if(l == r){
        tree[node].min = v[l];
        tree[node].qmin = 1;
        return;
    }

    int mid = (l+r)/2;

    build(2*node, l, mid);
    build(2*node + 1, mid + 1, r);

    tree[node].min = min(tree[2*node].min, tree[2*node+1].min);
    tree[node].qmin = 0;
    if(tree[node].min == tree[2*node].min)
        tree[node].qmin += tree[2*node].qmin;
    
    if(tree[node].min == tree[2*node+1].min)
        tree[node].qmin += tree[2*node+1].qmin; 
}

void update(int node, int l, int r, int id, int x){
    if(l == r){
        tree[node].min = x;
        tree[node].qmin = 1;
        return;
    }

    int mid = (l+r)/2;

    if(id <= mid) update(2*node, l, mid, id, x);
    else update(2*node+1, mid+1, r, id, x);

    tree[node].min = min(tree[2*node].min, tree[2*node+1].min);
    tree[node].qmin = 0;
    if(tree[node].min == tree[2*node].min)
        tree[node].qmin += tree[2*node].qmin;
    
    if(tree[node].min == tree[2*node+1].min)
        tree[node].qmin += tree[2*node+1].qmin;
}

TREE query(int node, int l, int r, int p, int q){
    if(r < p || q < l){
        TREE aux;
        aux.min = INF;
        aux.qmin = 0;
        return aux;
    } 
    if(p <= l && r <= q) return tree[node];

    int mid = (l+r)/2;

    TREE retorno1 = query(2*node, l, mid, p ,q);
    TREE retorno2 = query(2*node + 1, mid + 1, r, p, q);

    if(retorno1.min < retorno2.min){
        return retorno1;
    }
    else if(retorno2.min < retorno1.min)
        return retorno2;
    else{
        TREE retorno3;
        retorno3.min = retorno1.min;
        retorno3.qmin = retorno1.qmin + retorno2.qmin;
        return retorno3;
    } 
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
        b++;
        if(a == 1){
            update(1, 1, n, b, c);
        }
        else{
            TREE ans = query(1,1, n, b, c);
            cout << ans.min << " " << ans.qmin << endl;
        }
    }
}