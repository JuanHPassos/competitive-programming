#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, A = 0, B = 0, I;
    cin >> N;
    for(int j = 0; j<N; j++){
        cin >> I;
        if (I == 1)
            A = !A;
        else{
            A = !A;
            B = !B; }       
    }
    cout << A << '\n' << B;
    return 0;
}