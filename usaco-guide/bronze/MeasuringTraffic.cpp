#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main(){
  ifstream cin("traffic.in");  // Read from file
  ofstream cout("traffic.out"); // Write to file

  int n, A[100], B[100];
  string T[100];

  int a = 0, b = INF;

  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> T[i] >> A[i] >> B[i];
  }

  for(int i = n - 1; i >= 0; i--){
    if(T[i] == "none"){
      a = max(a, A[i]);
      b = min(b, B[i]);
    } else if (T[i] == "on") {
      a = max(0, a - B[i]);
      b = max(0, b - A[i]);
    } else {
      a += A[i];
      b += B[i];
    }
  }

  cout << a << " " << b << "\n";
  
  a = 0;
  b = INF;

  for(int i = 0; i < n; i++){
    if(T[i] == "none"){
      a = max(a, A[i]);
      b = min(b, B[i]);
    } else if (T[i] == "on") {
      a += A[i];
      b += B[i];
    } else {
      a = max(0, a - B[i]);
      b = max(0, b - A[i]);
    }
  }

  cout << a << " " << b << "\n";
}