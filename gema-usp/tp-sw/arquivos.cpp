#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, b;
    cin >> n >> b;
    vector<int> p(n);
    for(int i = 0; i<n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    int cont = 0, l = 0, r = n-1;
    while(l <= r){
        if(p[l]+p[r] <= b) l++;
        r--; cont++;
    }
    cout << cont << "\n";
    return 0;
}
