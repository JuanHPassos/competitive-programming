#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    vector<int> jog(n);
    for(int i = 0; i<n; i++){
        cin >> jog[i];
    }
    sort(jog.begin(), jog.end());
    int l, r = 0, tam = 1, ans = 0;
    for(l = 0; l < n; l++){
        while(r < n && jog[r]-jog[l] <= 5){
            ans = max(ans, tam);
            r++; tam++; 
        }
        tam--;
    }
    cout << ans << endl;
    return 0;
}
