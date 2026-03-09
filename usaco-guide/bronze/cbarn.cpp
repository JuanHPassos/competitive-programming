#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int n;
vector<int> cows(1e3 + 10);
int maxCows;

int runPath(int room, int dir){
  int total = maxCows;
  total -= cows[room];
  room = (room + dir);
  // Ajustando estrutura circular
  if(room == -1) room = n - 1;
  else if(room == n) room = 0;

  int mov = 0;
  while(total != 0){
    mov += total;
    total -= cows[room];
    room = (room + dir);
    // Ajustando estrutura circular
    if(room == -1) room = n - 1;
    else if(room == n) room = 0;
  }
  return mov;
}

int main(){
  ifstream cin("cbarn.in");
  ofstream cout("cbarn.out");
  
  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> cows[i];
    maxCows += cows[i];
  }

  int ans = INF;
  // Percorrer cada quarto
  for(int i = 0; i < n; i++){
    // Pelas duas direções possiveis
    ans = min(ans, runPath(i, 1));
    // ans = min(ans, runPath(i, -1));
  }  

  cout << ans;
}