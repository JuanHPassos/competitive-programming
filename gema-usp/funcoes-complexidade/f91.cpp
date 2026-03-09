#include <bits/stdc++.h>
using namespace std;
int f91(int n){
    if(n > 100)
        return n - 10;
    return  f91(f91(n+11));
}
int main(){
    int n;
    cin >> n;
    while(n != 0){
        cout << "f91(" << n << ") = " << f91(n) << '\n';
        cin >> n;
    }
    return 0;
}