#include <bits/stdc++.h>
using namespace std;
int main(void){
    int x, cont = 2;
    cin >> x;
    cout << ("1 ");
    while (cont <= x){
        if(x%cont == 0)
            cout << cont << " ";
        cont = cont + 1;
    }    
    return 0;
}
