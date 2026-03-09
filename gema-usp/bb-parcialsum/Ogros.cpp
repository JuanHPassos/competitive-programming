#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli inf = 1e10+5;
const lli MAXN = 1e6;
int main(){
    lli n, m, f, x;
    set<lli> inter;
    vector<lli> keep(MAXN);
    map<lli, lli> prem;
    cin >> n >> m;
    for(int i = 0; i<n-1; i++){ 
        cin >> x; 
        inter.insert(x);
        keep[i] = x;}
    inter.insert(inf);
    keep[n-1] = inf;
    for(int i = 0; i<n; i++){
        cin >> x;
        prem[keep[i]] = x;
    }
    while(m--){
        cin >> f;
        auto ptr = inter.lower_bound(f);
        if(*ptr == f) ptr++;
        cout << prem[*ptr] << " ";

    }
    return 0;
}