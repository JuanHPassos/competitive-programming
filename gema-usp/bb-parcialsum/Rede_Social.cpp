#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli MAXN = 1e6;
int main(){
    lli n, ans;
    vector<lli> r(MAXN);
    cin >> n;
    ans = n;
    for(int i = 0; i <n; i++) cin >> r[i];
    sort(r.begin(), r.begin()+n);
    for(int i = 0; i < n; i++){
        if(ans > r[i]) ans--;}
    cout << ans;
    return 0;
}