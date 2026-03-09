#include<bits/stdc++.h>
using namespace std;

const int ESTRADA = 100;

int main(){
  ifstream cin("speeding.in");
  ofstream cout("speeding.out");
  
  int n, m;
  cin >> n >> m;

  int limit[ESTRADA];
  int comeco = 0;
  for(int i = 0; i < n; i++){
    int tam, vel;
    cin >> tam >> vel;
    for(int milha = comeco; milha < comeco + tam; milha++){
      limit[milha] = vel;
    }
    comeco += tam;
  }

  comeco = 0;

  int bessie[ESTRADA]; 
  for(int i = 0; i < m; i++){
    int tam, vel;
    cin >> tam >> vel;
    for(int milha = comeco; milha < comeco + tam; milha++){
      bessie[milha] = vel;
    }
    comeco += tam;
  }

  int resposta = 0;
  for(int milha = 0; milha < ESTRADA; milha++){
    resposta = max(resposta, bessie[milha] - limit[milha]);
  }

  cout << resposta;

  return 0;
}
