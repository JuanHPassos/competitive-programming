#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
typedef long long int lli;
lli n,t;
vector<lli> k(MAXN);
int pos(lli med){
    if(med == 0) return 0;
    lli prod = 0;
    for(int i = 0; i<n; i++){
        if(med/k[i] > t - prod){
            prod = t;
            break;
        }
        prod += med/k[i];
    }
    if(prod >= t) return 1;
    else return 0;
}
 
int main(){
    cin >> n >> t;
    for(int i = 0; i< n; i++){
        cin >> k[i];
    }
    lli l = 0, r = 1e18+10;
    while(l < r){
        lli med = (l+r)/2;
        if(pos(med)) r = med;
        else l = med+1;
    } 
    cout << r << '\n';
    return 0;
}
