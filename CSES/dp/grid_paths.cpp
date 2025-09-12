#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 10;
const int MOD = 1e9 + 7;
 
string grid[MAXN];
int number_of_paths[MAXN][MAXN];
 
int num_paths(int x, int y, int max_n)
{
  if (x >= 0 && y >= 0 && x < max_n && y < max_n && grid[x][y] != '*')
    return number_of_paths[x][y];
  else
    return 0;
}
 
int main(void)
{
  int n; cin >> n;
 
  for(int i = 0; i < n; i ++) for(int j = 0; j < n; j++) number_of_paths[i][j] = 0;
 
  for(int i = 0; i < n; i++) cin >> grid[i];
 
  number_of_paths[0][0] = 1;
  for(int i = 0; i < n; i ++)
  {
    for(int j = 0; j < n; j++)
    {
      if(grid[i][j] != '*')
        number_of_paths[i][j] = num_paths(i - 1, j, n) + 
                                num_paths(i, j - 1, n) + 
                                number_of_paths[i][j]; 
      else number_of_paths[i][j] = 0;
 
      number_of_paths[i][j] %= MOD;
    }
  }
 
  cout << number_of_paths[n - 1][n - 1];
 
  return 0;
}