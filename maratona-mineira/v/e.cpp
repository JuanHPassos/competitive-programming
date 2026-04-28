#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    string primeiro;
    set<string> filhos;       // quem tem pai (nunca pode ser raiz)
    map<string, string> dino; // pai -> filho

    for(int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;
        dino[b] = a;          // b é pai, a é filho
        filhos.insert(a);     // a tem pai, logo não é raiz
    }

    // Raiz: está em dino (como pai) mas nunca foi filho
    for(auto& u : dino)
    {
        if(!filhos.count(u.first)) primeiro = u.first;
    }

    // Caminha da raiz até a folha
    while(dino.count(primeiro))
    {
        cout << primeiro << "\n";
        primeiro = dino[primeiro];
    }

    cout << primeiro << "\n";

    return;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;

}