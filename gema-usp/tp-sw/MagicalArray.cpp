#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli valor(lli v){
    if(v == 1) return 1;
    return valor(v-1)+v;
}
 
int main(){
    int n;
    cin >> n;
    vector<lli> num(n);
    for(int i = 0; i<n; i++) cin >> num[i];
    lli l, r = 0, sum = 0;
    for(l = 0; l < n; l = r){
        while(r < n && num[l] == num[r]) r++;
        sum += valor(r-l);
    } 
    cout << sum << "\n";
    return 0;
}
