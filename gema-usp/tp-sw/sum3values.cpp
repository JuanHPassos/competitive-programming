#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, x;
    cin >> n >> x;
    vector<pair<int,int>> num(n);
    for(int i =0; i<n; i++){
        cin >> num[i].first;
        num[i].second = i+1;
    }
    sort(num.begin(), num.end());
    int pos = 0;
    vector<int> resp;
    for(int l = 0; l < n-2; l++){
        int mid = l+1;
        int r = n-1;
        while(mid < r){
            if(num[l].first +num[mid].first + num[r].first == x){
                resp.push_back(num[l].second);
                resp.push_back(num[mid].second);
                resp.push_back(num[r].second);
                pos = 1;
                break;
            }
            else if(num[l].first + num[mid].first + num[r].first > x){
                r--;
            }
            else
                mid++;
        }
        if(pos == 1) break;
    }   
    if(pos == 0) cout << "IMPOSSIBLE" << "\n";
    else{
        sort(resp.begin(), resp.end());
        for(auto ans : resp) cout << ans << " ";
    }
    cout << "\n";
    return 0;
}
