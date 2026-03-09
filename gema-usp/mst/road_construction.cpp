#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2*1e5 + 10;

vector<int> ligacao(MAXN);
vector<int> tam(MAXN);

int n, m;
int quantComp;
int maior = -1;

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
  // Lógica do problema
  if(r1 == r2) return;
  else quantComp--;

  if(tam[r1] < tam[r2]) swap(r1, r2);
  tam[r1] += tam[r2];
  if(tam[r1] > maior) maior = tam[r1];
  ligacao[r2] = r1;
}

int main(void)
{
  cin >> n >> m;

  quantComp = n;
  ini();
  while(m--)
  {
    int a, b;
    cin >> a >> b;
    uniao(a,b);

    cout << quantComp << " " << maior << endl;
  }
  return 0;
}