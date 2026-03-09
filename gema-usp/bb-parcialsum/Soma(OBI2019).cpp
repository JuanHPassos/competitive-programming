#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5+10;
vector<int> prex(MAXN, 0);
vector<int> mud(MAXN, 0);
long long int ans;
int n, k, x;
int buscab(int u){
    int l = u, r = n, resp = -1;
    while(l <= r){
        int mid = (l+r)/2;
        if(prex[mid] - prex[u-1] == k){
            resp = mid;
            l = mid+1;}
        else if(prex[mid] - prex[u-1] > k) r = mid-1;
        else l = mid+1;
    }
    return resp;
}


int main(){
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        cin >> x;
        prex[i+1] = prex[i] + x;
        if(prex[i+1] == prex[i]){
            mud[i+1] = mud[i];
        }
        else mud[i+1] = i+1;
    }
    for(int i = 1; i<=n; i++){
        int temp = buscab(i);
        if(temp == -1) continue;
        ans += temp-max(i,mud[temp])+1;
    }
    cout << ans;
}
