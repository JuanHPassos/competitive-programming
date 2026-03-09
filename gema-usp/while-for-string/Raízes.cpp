#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    double raiz[n]; 
    for(int i = 0; i<n; i++)
        cin >> raiz[i];
    for(int i = 0; i<n; i++){
        cout << setprecision(4) << fixed;
        cout << sqrt(raiz[i]) << endl;}
    return 0;
}