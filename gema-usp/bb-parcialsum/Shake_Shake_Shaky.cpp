#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
long long int n, k;
vector<long long int> box(MAXN);
int pos(int med){
    long long int cont = 0;
    if(med == 0) return 0;
    for(int i = 0; i<n; i++){
        if(box[i] >= med){
            cont += box[i]/med;
        }
    }
    if(cont > k-1) return 0;
    else return 1;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    long long int l, r;
    long long int t;
    cin >> t;
    while(t--){
        long long int lim = -1;
        cin >> n >> k;
        for(int i = 0; i<n; i++){
            cin >> box[i];
            lim = max(box[i], lim);
        }
        l = 0; r = lim+1;
        while(l < r){
            long long int med = (l+r)/2;
            if(pos(med)) r = med;
            else l = med+1;
        }
        r--;
        cout << r << '\n';
    }
    return 0;
}