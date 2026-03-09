#include<bits/stdc++.h>
using namespace std;

int main(){

  ifstream cin("blist.in");  // Read from file
  ofstream cout("blist.out"); // Write to file

  int n;
  cin >> n;
  // Instante, baldes e flag se entrada e saida.
  vector<tuple<int, int, int>> cows;
  int ans = 0;

  for(int i = 0; i < n; i++){
    int s, t, b;
    cin >> s >> t >> b;
    // 0 é entrada e 1 é saida.
    cows.push_back({s, b, 0});
    cows.push_back({t, b, 1});
  }

  sort(cows.begin(), cows.end());

  int baldes = 0;
  for(int i = 0; i < cows.size(); i++){
    int a = get<0>(cows[i]);
    int b = get<1>(cows[i]);
    int c = get<2>(cows[i]);

    if (c == 0) {
      baldes += b;
      ans = max(ans, baldes);
    } else {
      baldes -= b;
    }
  }

  cout << ans;

  return 0;
}
