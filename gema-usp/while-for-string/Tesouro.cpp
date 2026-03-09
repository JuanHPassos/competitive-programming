#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n, x, y, i = 0;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    for(int cont=0; cont < n; cont++){
        if(s[0+cont] == 'C')
            x = x - 1;
        if(s[0+cont] == 'B')
            x = x + 1;
        if(s[0+cont] == 'D')
            y = y + 1;
        if(s[0+cont] == 'E')
            y = y - 1;
        
    }
    cout << x << " " << y;
    return 0;
}