#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

long long int dp[105][MAXN];
int n, m;
int x[MAXN];

bool valid(int i)
{
  return (i > 0 && i <= m);
}

int main(void)
{
  cin >> m >> n;

  for(int j = 1; j <= m; j++) cin >> x[j];

  for(int j = 1; j <= m; j++)
  {
    if(x[j])
    {
      if(!valid(j - 1)) dp[x[j]][j] = 1; 
      else
      {
        dp[x[j]][j] = dp[x[j] - 1][j - 1]%MOD + 
                      dp[x[j]][j - 1]%MOD + 
                      dp[x[j] + 1][j - 1]%MOD;
        dp[x[j]][j] %= MOD;
      }
    } 
    else 
    {
      for(int i = 1; i <= n; i++)
      {
        if(valid(j - 1))
        {
          dp[i][j] = dp[i - 1][j - 1]%MOD + 
                    dp[i][j - 1]%MOD + 
                    dp[i + 1][j - 1]%MOD;
          dp[i][j] %= MOD;
        } 
        else 
        {
          dp[i][j] = 1;
        }
      }
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++)
  {
    ans += dp[i][m];
    ans %= MOD;
  }

  cout << ans;
}