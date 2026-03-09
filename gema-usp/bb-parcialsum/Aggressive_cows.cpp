#include<bits/stdc++.h>
using namespace std;
int t, n, c;
vector<int> stall(100010);
int pos(long long int med){
    int ans = 1;
    int ult_pos = stall[0];
    for(int i = 1; i < n; i++){
        if(stall[i] - ult_pos >= med){
            ans++;
            ult_pos = stall[i];
            if(ans == c) return 1;
        }
    }
    return 0;
}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> t;
    while(t--){
        cin >> n >> c;
        for(int i = 0; i<n; i++){
            cin >> stall[i];
        }
        sort(stall.begin(), stall.begin() + n);
        long long int r = 1e9, l = 1;
        while(l < r){
            long long int med = (r+l)/2;
            if(pos(med)) l = med+1;
            else r = med;
        }
        cout << l-1 << endl;
    }
}