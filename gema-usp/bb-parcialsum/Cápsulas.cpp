#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+10;
vector<int> cap(MAXN);
int n, f;
bool pos(int med){
    int moedas = 0;
    for(int i = 0; i<n; i++){
        moedas += med/cap[i];
    }
    if(moedas >= f) return 1;
    else return 0;
}


int main(){
    cin >> n >> f;
    for(int i = 0; i<n; i++){
        cin >> cap[i];
    }
    int r = 1e8+10, l = 0;
    while(l < r){
        int med = (l+r)/2;
        if(pos(med)) r = med;
        else l = med+1; 
    }
    cout << r << '\n';
    return 0;
}