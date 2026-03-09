#include<bits/stdc++.h>
using namespace std;

int main(){
  // ifstream cin("lostcow.in");
  // ofstream cout("lostcow.out");

  int x, y;
  cin >> x >> y;

  int ans = 0;
  int atual = x;
  for(int i = 0; ; i++){
    int novox;
    if(i%2) 
      novox = x - pow(2, i);
    else
      novox = x + pow(2, i);
   
    if((!(i%2) && novox >= y && y >= atual) || ((i%2) && novox <= y && y <= atual)) {
      ans += abs(atual - y); 
      break;
    }

    ans += abs(novox - atual);
    atual = novox;
  }

  cout << ans;

  return 0;
}