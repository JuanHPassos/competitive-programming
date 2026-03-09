#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a;
    string s;
    cin >> s;
    for(int i=1; i<(s.size()-1); i++){
        if(s[i] == '=')
            a = 1;
        else{
            a = 0;
            break;}
    }    
    
    if((s[0] == '<' && a && s[s.size()-1] == '>') == true )
        cout << "Yes";
    else
        cout << "No";
    return 0;
    
}