#include <bits/stdc++.h>
using namespace std;
int m[110][110];
int main(){ 
    for(int i = 0; i<110; i++)
        for(int j = 0; j<110; j++)
            m[i][j] = 0;
    int n;
    cin >> n;
    int xi, xf, yi, yf;
    for(int i = 0; i<n; i++){
        cin >> xi >> xf >> yi >> yf;
        for(int k = yi; k < yf; k++){
            for(int l = xi; l < xf; l++)
                m[k][l] = 1;}
    }
    int rede = 0;
    for(int i = 0; i<110; i++)
        for(int j = 0; j<110; j++)
            if(m[i][j] == 1)
                rede++;
    cout << rede << '\n';
}
