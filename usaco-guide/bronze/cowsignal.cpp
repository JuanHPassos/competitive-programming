#include<bits/stdc++.h>
using namespace std;

int main(void){
  ifstream cin("cowsignal.in");  // Read from file
  ofstream cout("cowsignal.out"); // Write to file

  int m, n, k;
  cin >> m >> n >> k;
  string line[10];
  
  for(int i = 0; i < m; i++) {
    cin >> line[i];
  }

  for(int i = 0; i < m; i++) {
    for(int b = 0; b < k; b++) {
      for(int j = 0; j < n; j++) {
        for(int a = 0; a < k; a++){
          cout << line[i][j];
        }
      }
      cout << "\n";
    }
  }

  return 0;
}