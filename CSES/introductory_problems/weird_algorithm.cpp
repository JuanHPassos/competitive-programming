// Conjectura de Collatz
#include<iostream>
using namespace std;

#define int long long int

signed main(void)
{
  int n; cin >> n;
  
  while(true)
  {
    cout << n << " ";
    if(n == 1) break;
    else if(n%2) n = n*3 + 1;
    else n /= 2; 
  }

  return 0;
}