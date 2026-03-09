#include <bits/stdc++.h>
using namespace std;
int main(){
    int matriz[3][3], somal = 0, somac = 0, somad = 0;
    for( int i = 0; i<3; i++)
        for( int j = 0; j<3; j++)
            cin >> matriz[i][j];
    if(matriz[0][0]+matriz[0][1]+matriz[0][2] == matriz[1][0]+matriz[1][1]+matriz[1][2])
        if(matriz[1][0]+matriz[1][1]+matriz[1][2] == matriz[2][0]+matriz[2][1]+matriz[2][2])
            somal = matriz[0][0]+matriz[0][1]+matriz[0][2];
        else{
            cout << "NAO";
            return 0;}
    else{
        cout << "NAO";
        return 0;}
    if(matriz[0][0]+matriz[1][0]+matriz[2][0] == matriz[0][1]+matriz[1][1]+matriz[2][1])
        if(matriz[0][1]+matriz[1][1]+matriz[2][1] == matriz[0][2]+matriz[1][2]+matriz[2][2])
            somac = matriz[0][0]+matriz[1][0]+matriz[2][0];
        else{
            cout << "NAO";
            return 0;}
    else{
        cout << "NAO";
        return 0;}
    if(matriz[0][0]+matriz[1][1]+matriz[2][2] == matriz[0][2]+matriz[1][1]+matriz[2][0])
        somad = matriz[0][0]+matriz[1][1]+matriz[2][2];
    else{
        cout << "NAO";
        return 0;}
    if(somal == somac && somac == somad)
        cout << "SIM";
    else 
        cout << "NAO";
    return 0;
}    