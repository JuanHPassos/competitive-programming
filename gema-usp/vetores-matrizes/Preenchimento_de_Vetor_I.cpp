#include <bits/stdc++.h>
using namespace std;
int main(){
    int N[11];
    cin >> N[0];
    for(int i = 0; i<10; i++){
        N[i+1] = N[i]*2;
        cout << "N[" << i << "] = " << N[i] << '\n';
    }    
    return 0;
}