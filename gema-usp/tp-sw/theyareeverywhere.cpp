#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n, tam = 0;
    cin >> n;
    set<char> let;
    string pok;
    cin >> pok;
    for(int i = 0; i<n; i++) let.insert(pok[i]);
    multiset<char> alf;
    int l = 0, r = 0, ans = n;
    while(l <= r){
        if(let.size() == tam){
            ans = min(ans, r-l);
            alf.erase(alf.find(pok[l]));
            if(alf.find(pok[l]) == alf.end()) tam--;
            l++;
        }
        else if(r<n){
            if(alf.find(pok[r]) == alf.end()) tam++; 
            alf.insert(pok[r]);
            r++;
        }
        else
            break;
    }
    cout << ans << "\n";
    return 0;
}
