#include<iostream>
using namespace std;

#define int long long int

signed main(void)
{
  /*
  Os zeros do fatorial surgem de 10,
  que são formados pela multiplicação de 
  5 e 2. A quantidade de *5, que aparece,
  é a quantidade de 0.
  */
  int n; cin >> n;
  int zeros = 0;

  int pot = 5;
  while(n/pot)
  { 
    zeros += n/pot;
    pot *= 5;
  }

  cout << zeros;

  return 0;
}