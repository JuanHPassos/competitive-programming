#include<bits/stdc++.h>
using namespace std;
#define RMV 0
#define ADD 1
vector<pair<int, bool>> client;
int n;
int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        int a, b;
        cin >> a >> b;
        client.push_back({a, ADD});
        client.push_back({b, RMV});
    }
    sort(client.begin(), client.end());
    int cont = 0, ans = 0;
    for(pair<int,bool> p : client){
        if(p.second) cont++;
        else cont--;
        ans = max(ans, cont);
    }
    cout << ans;
    return 0;
}
