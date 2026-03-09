#include<iostream>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  long long int sequence[n];
  for(auto &u : sequence) cin >> u;

  long long int acm = 0; 

  for(int i = 1; i < n; i++)
  {
    if(sequence[i] - sequence[i - 1] < 0)
    {
      acm += sequence[i - 1] - sequence[i];
      sequence[i] = sequence[i - 1]; 
    }
  }

  cout << acm;

  return 0;
}