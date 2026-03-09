#include<bits/stdc++.h>
using namespace std;
vector<int> s = {1,5,10,25,50,100};
int v;
int main(){
    cin >> v;
    int i = 5, cont = 0;
    while(v){
        if(v >= s[i]){
            cont++;
            v -= s[i];
        }
        else i--;
    }
    cout << cont << endl;
    return 0;
}
