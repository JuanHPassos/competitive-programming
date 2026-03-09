#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2*1e3 + 10;
int mat[MAXN][MAXN];
int n; 

vector<int> ligacao(MAXN);
vector<int> tam(MAXN);

void ini()
{
  for(int i = 0; i < n; i++)
  {
    ligacao[i] = i;
    tam[i] = 1;
  }
}

int find(int x)
{
  // r = representante
  int r = x;
  while(r != ligacao[r]) r = ligacao[r];

  return r;
}

bool same(int a, int b)
{
  return find(a) == find(b);
}

bool uniao(int a, int b)
{
  int r1 = find(a);
  int r2 = find(b);
  if(r1 == r2) return false; 
  if(tam[r1] < tam[r2]) swap(r1, r2);
  tam[r1] += tam[r2];
  ligacao[r2] = r1;
  return true;
}

int main(void)
{
  cin >> n;
  bool sim = true;
  ini();
  for(int i = 0; i < n; i++) 
    for (int j = 0; j < n; j++) cin >> mat[i][j];

  for(int i = 0; i < n; i++) 
    for (int j = i + 1; j < n; j++)
    {
      if(same(i, j)) sim = false;
      else if(mat[i][j]) uniao(i, j);
    }


  for(int i = 0, j = 0; i < n && sim; i++, j++) 
    if(mat[i][j] != 0) sim = false;

  for(int i = 0; i < n && sim; i++) 
    for (int j = 0; j < n && sim; j++)
      if(mat[i][j] != mat[j][i]) sim = false;
  
  cout << (sim ? "YES" : "NO");
  
}