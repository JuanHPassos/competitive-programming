#include<iostream>
using namespace std;
const int MOD = 1e9 + 7;

int main(void)
{
  int n; cin >> n;

  int ans = 1;
  for(int i = 0; i < n; i++)
  {
    ans *= 2;
    ans %= MOD;
  }

  cout << ans;

  return 0;
}