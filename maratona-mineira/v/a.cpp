#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int vet[5];
    for(auto &u : vet) cin >> u;

    int temp = -1e6; 
    int sim = 1;
    for(int i = 0; i < 5; i++)
    {
        if(vet[i] < temp) sim = 0;
        temp = max(temp, vet[i]); 
    }

    cout << (sim ? "SIM" : "NAO") << endl;
}