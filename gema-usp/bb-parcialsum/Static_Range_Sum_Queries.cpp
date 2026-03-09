#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int MAXN = 1e6;
int main(){
    lli n, q, a, b, ans;
    vector<lli> vet(MAXN);
    vector<lli> prex_sum(MAXN, 0);
    cin >> n >> q;
    for(int i = 1; i<=n; i++){
        cin >> vet[i];
        prex_sum[i] = prex_sum[i-1] + vet[i];}
    for(int i = 1; i<=q; i++){
        cin >> a >> b;
        ans = prex_sum[b] - prex_sum[a-1];
        cout << ans << '\n';
    }
    return 0; 
}