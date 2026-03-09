#include<iostream>
using namespace std;

int main(void)
{
  int t; cin >> t;
  while(t--)
  {
    int a, b;
    cin >> a >> b;
    int n = abs(a - b);
    if ((a + b)%3 || n > a || n > b) cout << "NO";
    else cout << "YES";
    cout << endl; 
  }

  return 0;
}