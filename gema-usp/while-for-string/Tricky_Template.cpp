#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    cin >> t;
    for( int i=0; i<t; i++){
        int dif = 1;
        cin >> n;
        string a, b, c;
        cin >> a >> b >> c;
        for( int j = 0; j<n; j++){
            if( b[j] != c[j] && a[j] != c[j] ){
                cout << "YES" << '\n';
                dif = 0;
                break;}
        }
        if( dif == 1)
            cout << "NO" << '\n';
    }        
    
}