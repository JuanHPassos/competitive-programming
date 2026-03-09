#include<iostream>
using namespace std;

int main(void)
{
  string s; cin >> s;

  int ans = 1;
  pair<char,int> seq = {s[0], 1};

  for(int i = 1; i < s.size(); i++)
  {
    if(s[i] != seq.first)
    {
      seq.first = s[i];
      seq.second = 1;
    } else seq.second++;

    ans = max(ans, seq.second);  
  }

  cout << ans;

  return 0;
}