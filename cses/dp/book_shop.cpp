#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
 
#define pii pair<int,int>
 
vector<pii> h_s(MAXN);
 
int main(void)
{
  int n, x;
  cin >> n >> x;
  for(int i = 0; i < n; i++) cin >> h_s[i].first;
  for(int i = 0; i < n; i++) cin >> h_s[i].second;
 
  sort(h_s.begin(), h_s.end());
 
  vector<int> value(x + 10, 0);
 
  value[0] = 0;
  for(auto [price, page] : h_s)
  {
    for(int i = x; i >=0; i--)
    {
      if(i - price >= 0)
      {
        value[i] = max(value[i], value[i - price] + page);
      }
    }
  }
 
  cout << value[x];
 
  return 0;
}