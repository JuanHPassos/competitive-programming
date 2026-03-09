#include<iostream>
#include<map>
using namespace std;

int main(void)
{

    int n, x;
    cin >> n >> x;
    int vet[n + 1];
    for(int i = 1; i <= n; i++) cin >> vet[i];
    vet[0] = 0;

    long long prefix[n + 1];
    prefix[0] = 0;
    map<long, long> prefix_values;
    prefix_values[0] = 1;
    long ans = 0;
    // Construir vetor de prefixos
    for(int i = 1; i <= n; i++) 
    {
        // Intervalo l e r tem soma x se
        // se há um intervalo com soma 0 e l - 1
        // com soma (0 e r) - x
        prefix[i] = prefix[i - 1] + vet[i];
        if(prefix_values.count(prefix[i] - x)) 
            ans += prefix_values[prefix[i] - x];    
        
        prefix_values[prefix[i]]++;
    }

    cout << ans;

    return 0;
}