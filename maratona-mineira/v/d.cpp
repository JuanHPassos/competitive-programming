#include<bits/stdc++.h>
using namespace std;
#define ld long double
const ld PI = 3.14159265358979;
const ld E = 2.71828182845905;

pair<int,int> vogais_consoantes(string s)
{
    int v_s = 0;
    int c_s = 0;
    set<char> vogais = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
        if(vogais.count(s[i])) v_s++;
        else c_s++;
    }

    return {v_s, c_s};
}

ld binomio_newton(ld cima, ld baixo)
{
    ld ans = 1.0;
    ld temp_cima = cima;
    ld temp_baixo = baixo;
    for(int i = 0; i < baixo; i++)
    {
        ans *= temp_cima/temp_baixo;
        temp_baixo--;
        temp_cima--;
    }

    return ans;
}

ld somatorio(int t_s, ld p)
{
    ld ans = 0.0;
    for(int k = 1; k <= t_s; k++)
    {   
        ans += pow(p, 1.0/k)*cos(k*PI);
    }
    
    return fabs(ans);
}

ld IMAD(string s, ld a, ld c, ld p)
{
    pair<int,int> aux = vogais_consoantes(s);
    int v_s = aux.first;
    int c_s = aux.second;

    // Formula
    ld imad = somatorio(s.size(), p)*
            binomio_newton(max(v_s, c_s) + 1, min(v_s, c_s) - 1)*
            (ceil(sqrt(pow(v_s, E) + pow(c_s, E)))/floor(PI + (log(1 + a*c)/log(E))));

    return imad;
}

int main(void)
{
    int n; cin >> n;
    vector<pair<ld, string>> dinos;

    for(int i = 0; i < n; i++)
    {
        string s;
        ld a, c, p;
        cin >> s >> a >> c >> p;
        dinos.push_back({IMAD(s, a, c, p), s});
    }

    sort(dinos.begin(), dinos.end());

    for(int i = 0; i < n; i++)
    {
        // cout << dinos[i].first << " "; 
        cout << dinos[i].second;
        
        long long parte_inteira = floor(dinos[i].first);
        string digitos = to_string(parte_inteira);
        for(int j = 0; j < digitos.size(); j++) cout << "!";

        cout << endl;
    }

    return 0;
}