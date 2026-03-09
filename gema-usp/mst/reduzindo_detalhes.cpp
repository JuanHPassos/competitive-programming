#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2*1e5 + 10;
int n;

vector<int> ligacao(MAXN);
vector<int> tam(MAXN);

void ini()
{
  for(int i = 1; i <= n; i++)
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

void uniao(int a, int b)
{
  int r1 = find(a);
  int r2 = find(b);
  if(tam[r1] < tam[r2]) swap(r1, r2);
  tam[r1] += tam[r2];
  ligacao[r2] = r1;
}

int main(void)
{
  // Vetices
  cin >> n;
  // Operações
  int m; cin >> m;

  ini();
  // Peso, e vertices.
  priority_queue<pair<int, pair<int,int>>> floresta;

  while(m--)
  {
    int a, b, w;
    cin >> a >> b >> w;
    floresta.push({-w, {a, b}});
  }

  int caminho = 0;
  while(!floresta.empty())
  {
    int w = -floresta.top().first;
    int a = floresta.top().second.first;
    int b = floresta.top().second.second;
    floresta.pop();
    if(!same(a, b))
    {
      uniao(a, b);
      caminho += w;
    }
  }

  cout << caminho;
}