// Imprimir todos os impares e depois todos os pares.
#include<iostream>
using namespace std;

int main(void)
{
  int n; cin >> n;

  if(n == 2 || n == 3) cout << "NO SOLUTION";
  else
  {
    for(int i = 2; i <= n; i = i + 2) cout << i << " ";
    for(int i = 1; i <= n; i = i + 2) cout << i << " ";
  }

  return 0;
}
