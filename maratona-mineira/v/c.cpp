#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int r, v;
    cin >> r >> v;

    map<string, int> comp;
    vector<set<int>> dinos;
    for(int i = 0; i < r; i++)
    {
        string pai, filho;
        cin >> pai >> filho;
        
        if(!comp.count(pai))
        {
            comp[pai] = dinos.size();
            dinos.push_back({});
        }

        if(!comp.count(filho))
        {
            comp[filho] = dinos.size();
            dinos.push_back({});    
        }

        dinos[comp[pai]].insert(comp[filho]);
    }

    for(int i = 0; i < v; i++)
    {
        string pai, filho;
        cin >> pai >> filho;

        if(comp.count(pai) && dinos[comp[pai]].count(comp[filho]))
            cout << "Nao e a mamae" << endl;
        else
            cout << "nao e o Nao e a mamae" << endl;
    }

    return 0;
}