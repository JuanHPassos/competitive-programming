/*
Problema da moeda para calcular numero de soluções.
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
 
 
int main(void)
{
  int n, x; cin >> n >> x;
 
  int coins[n];
  vector<int> value(MAXN, 0);
 
  for(auto &c : coins) cin >> c;
 
  value[0] = 1;
  for(int i = 1; i <= x; i++)
  {
    for(auto c : coins)
    {
      if(i - c >= 0)
      {
        value[i] += value[i - c];
        value[i] %= MOD;       
      }
    }
  }
 
  cout << value[x];
 
  return 0;
}