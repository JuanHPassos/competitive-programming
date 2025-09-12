#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
 
int main(void)
{
  int n; cin >> n;
 
  vector<int> value(MAXN, INF);
 
  value[0] = 0;
  for(int i = 0; i <= n; i++)
  {
    int num = i;
    int best = INF;
    while(num != 0)
    {
      if(value[(i - num%10)] != INF)
      {
        best = min(best, value[(i - num%10)] + 1);
      }      
      num = num/10;
    }
    if(best != INF) value[i] = best;
  }
 
  cout << value[n];
 
  return 0;
}