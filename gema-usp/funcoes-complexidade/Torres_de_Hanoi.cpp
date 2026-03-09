#include <bits/stdc++.h>
using namespace std;
int hanoi(int n){
    if( n == 1)
        return 1;
    return pow(2, n-1) + hanoi(n-1);
}
int main(){
    int n, cont =1;
    cin >> n;
    while(n != 0){
        cout << "Teste " << cont << '\n' << hanoi(n) << '\n' << '\n';
        cin >> n;
        cont++;
    }
    return 0;
}