#include<iostream>
using namespace std;

int main(void)
{
  int n; cin >> n;
  int vet[n] = { 0 };
  for(int i = 0; i < n; i++)
  {
    int a; cin >> a;
    vet[--a] = 1;
  }

  for(int i = 0; i < n; i++)
  {
    if(vet[i] == 0)
    {
      cout << i + 1;
      break;
    }
  }

  return 0;
}