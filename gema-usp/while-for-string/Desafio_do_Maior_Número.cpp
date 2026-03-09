#include <bits/stdc++.h>
using namespace std;
int main(void){
  int n=1, acm = 0;
  while (n != 0){
    if (n == 0)
        break;
    else
        cin >> n;
        if (n>acm)
            acm = n;
      
  }
  cout << acm;
  return 0;
}