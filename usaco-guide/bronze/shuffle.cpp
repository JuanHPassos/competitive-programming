#include<bits/stdc++.h>
using namespace std;

int main(){
  ifstream cin("shuffle.in");
  ofstream cout("shuffle.out");

  int n;
  cin >> n;

  vector<int> ids(n);
  vector<int> emb(n);
  vector<int> antpos(n);

  for(int i = 0; i < n; i++){
    cin >> emb[i];
  }
  for(int i = 0; i < n; i++){
    cin >> ids[i];
  }

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < n; j++){
      antpos[j] = ids[emb[j] - 1];
    }
    ids = antpos; // Cria uma copia de antpos e atribui a ids.
  }

  for(int i = 0; i < n; i++){
    cout << ids[i] << "\n";
  }

  return 0;
}