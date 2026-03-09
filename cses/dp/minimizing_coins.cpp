/*
Problema comum da moeda usando memorização.
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const int INF = 1e9 + 10;
 

int main(void)
{
  int n, x;
  cin >> n >> x;
 
  int coins[n];
  for(auto &c : coins) cin >> c;

  vector<int> value(MAXN);
  value[0] = 0;
  
  for(int i = 1; i <= x; i++)
  {
    value[i] = INF;
    for(auto c : coins)
    {
      if(i - c >= 0)
      {
        value[i] = min(value[i], value[i - c] + 1);
      }
    }
  }
 
  cout << (value[x] == INF ? -1 : value[x]);
 
  return 0;
}