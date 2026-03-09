#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
const int INF = 1e9+2;

int tree[4*MAXN];
int v[MAXN];

void build(int node, int l, int r){
    if(l == r){
        tree[node] = v[l];
        return;
    }
    int mid = (l+r)/2;

    build(2*node, l, mid);
    build(2*node + 1, mid+1, r);

    tree[node] = min(tree[2*node], tree[2*node+1]);
}

void update(int node, int l, int r, int id, int x){
    if(l == r){
        tree[node] = x;
        return;
    }

    int mid = (l+r)/2;

    if(id <= mid) update(2*node, l, mid, id, x);
    else update(2*node + 1, mid + 1, r, id, x);

    tree[node] = min(tree[2*node], tree[2*node + 1]);
}

int query(int node, int l, int r, int p, int q){
    if(r < p || l > q) return INF;
    if(p <= l && r <= q){
        return tree[node];
    }

    int mid = (l+r)/2;

    return min(query(2*node, l, mid, p, q), query(2*node + 1, mid + 1, r, p, q));
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
            int ans = query(1, 1, n, b, c);
            cout << ans << endl;
        }
    }

}