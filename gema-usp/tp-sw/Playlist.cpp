#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    set<int> list;
    cin >> n;
    vector<int> pl(n);
    for(int i = 0; i<n; i++) cin>>pl[i];
    int l, r = 0, tam = 0, ans = 0;
    for(l = 0; l<n; l++){
        while(r < n && list.find(pl[r]) == list.end()){
            list.insert(pl[r]);
            tam++;
            r++;
            ans = max(ans, tam);
        }
        list.erase(pl[l]);
        tam--;
    }
    cout << ans << "\n";
    return 0;
}
