#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n;
    string s;
    cin >> t;
    for(int i = 0; i<t; i++){
        cin >> n;
        cin >> s;
            for(int j = 0; j<n; j++){
                if(s[j] == 'a' || s[j] == 'e'){
                    if(j == n-1){
                        cout << s[j];
                        break;}
                    cout << s[j];
                    j++;
                    if(j == n-1){
                        cout << s[j];
                        break;}
                    else if(s[j+1] == 'a' || s[j+1] == 'e'){
                        cout << "." << s[j];
                    }
                    else
                        cout << s[j] << ".";}
                else
                    cout << s[j];
            }
        cout << '\n';
        
    }                
    return 0;
}