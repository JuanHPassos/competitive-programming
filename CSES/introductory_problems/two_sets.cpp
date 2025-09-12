#include<iostream>
#include<set>
using namespace std;

int main(void)
{
  int n; cin >> n;
  /*
    Nota-se que a soma de dois numeros do extremo,
    são iguais, logo se n par e a quantidades de 
    combinações do extremo for par, dá certo.
    Se o número é impar >= 3, podemos reduzir o problema
    para o problema do par.
  */ 
  set<int> s1;
  set<int> s2;
  int l = 1, r = n;

  if(n%2)
  {
    s1.insert(1);
    s1.insert(2);
    s2.insert(3);
    l = 4;
    n = n - 3;
  }
  
  if(n >= 0 && n%2 == 0 && (n/2)%2 == 0)
  {
    cout << "YES" << endl;
    for(int i = 0; l <= r; i++)
    {
      if(i%2)
      {
        s1.insert(l);
        s1.insert(r);
      } else {
        s2.insert(l);
        s2.insert(r);
      }
      
      r--;
      l++;
    }

    cout << s1.size() << endl;
    for(auto u : s1) cout << u << " ";
    cout << endl << s2.size() << endl;
    for(auto u : s2) cout << u << " ";
    cout << endl;
  } else cout << "NO" << endl; 
  
  return 0;
}