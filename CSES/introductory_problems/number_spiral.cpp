#include<iostream>
#include<math.h>
using namespace std;

#define int long long int

signed main(void)
{
  int n; cin >> n;

  while(n--)
  {
    int y, x; cin >> y >> x;

    int teto = max(x, y) * max(x, y);
    int chao = (max(x, y) - 1) * (max(x, y) - 1) + 1;
    
    if(y >= x) cout << (max(x,y)%2 ? chao + (x - 1) : teto - (x - 1));
    else cout << (max(x, y)%2 ? teto - (y - 1) : chao + (y - 1));

    cout << endl;
  }

  return 0;
}