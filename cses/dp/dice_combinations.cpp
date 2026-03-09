/*
Questão do problema da moeda:

Nesse problema consiste apenas em contar o número de soluções possíveis. Nessa caso as moedas são as faces do dado, e podemos jogar o dado o quanto quisermos, logo a quantidade de uma moeda é infinita. Dessa forma, se o valor a ser obtido for menor que zero, não há solução. Caso seja 0, a solução é o vazio(de graça KKKK). Além desses casos, a quantidade de solução para chegar no valor x é a soma de todas as formas de chegar em x por meio de uma das moedas, nesse caso as faces dos dados. 
*/

#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
const int MOD = 1e9 + 7;
 
int main(void)
{
  int n; cin >> n;
 
  vector<int> faces = { 1, 2, 3, 4, 5, 6 };
  vector<int> ways(MAXN, 0);
 
  ways[0] = 1;
  for(int i = 1; i <= n; i++) 
  {
    for(auto u: faces)
    {
      if(i - u >= 0)
      {
        ways[i] += ways[i - u];
        ways[i] %= MOD;
      }
    }
  }
 
  cout << ways[n];
 
  return 0;
}
