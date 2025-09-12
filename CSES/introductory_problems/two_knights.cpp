#include<iostream>
#include<vector>
using namespace std;

const int MAXN = 1e4+5;

int mat[MAXN][MAXN];

bool valid(int i, int j, int n)
{
  return (i >= 1 && j >= 1 && i <= n && j <= n && mat[i][j] == 1);
}

vector<pair<int,int>> movs = {{-2, 1}, {-2, -1},
                              {2, 1}, {2, -1}, 
                              {1, 2}, {-1, 2}, 
                              {1, -2}, {-1, -2},
                            };

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  cin >> n;
  int i = 1;
  int j = 1;

  int acm = 0;
  int quadrados = 0;

  while(i <= n && j <= n)
  {
    int quant = 0;
    for(auto mov : movs)
    {
      if(valid(i + mov.first, j + mov.second, max(i, j))) quant++;
    } 

    mat[i][j] = 1;
    quadrados++;

    acm += max(i, j)*max(i, j) - quadrados - quant;

    if(max(i,j)%2)
    {
      if(i == 1)
      {
        j++;
        cout << acm << endl;
        quadrados = 0;
      } 
      else if(j < i) j++;
      else i--;
    
    } else {
      if(j == 1)
      {
        i++;
        cout << acm << endl;
        quadrados = 0;
      }
      else if(i < j) i++;
      else j--;
    }
  }
  
  return 0;
}