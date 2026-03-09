#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second != b.second){
        //Se a for menor que b, ja ta certo.
        if(a.second < b.second) return true;
        else return false;
    }
    if(a.first < b.first) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> time(n);
    for(int i = 0; i < n; i++){
        cin >> time[i].first >> time[i].second;
    }
    sort(time.begin(), time.end(), cmp);
    int lasttime = 0, ans = 0;
    for(int i = 0; i<n; i++){
        if(lasttime <= time[i].first){
            ans++;
            lasttime = time[i].second;
        }
    }
    cout << ans << "\n";
}
