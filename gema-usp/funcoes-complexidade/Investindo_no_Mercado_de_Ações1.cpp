#include <bits/stdc++.h>
using namespace std;
int q(int n, int k){
    if(n > k){
        if( n%2  == 1)
            return q(n/2, k) + q((n+1)/2, k);
        else 
            return q(n/2, k) + q(n/2, k);}
    return 1;
}
int main(){
    int n, k;
    cin >> n >> k;
    while(n != 0 || k != 0){
        cout << q(n, k) << '\n';
        cin >> n >> k;
    }
    return 0;
}