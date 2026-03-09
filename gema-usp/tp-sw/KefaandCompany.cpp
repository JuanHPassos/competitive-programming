#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    int n, d;
    cin >> n >> d;
    vector<pair<lli,lli>> f(n);
    for(int i = 0; i<n; i++){
        cin >> f[i].first >> f[i].second; 
    }
    sort(f.begin(), f.end());
    lli l, r= 0, sum = 0, ans = 0;
    for(l = 0; l<n; l++){
        while(r < n && f[r].first-f[l].first < d){
            sum += f[r].second;
            r++;
            ans = max(ans, sum);
        }
        sum = abs(sum - f[l].second);
    }
    cout << ans << endl;
    return 0;
}
