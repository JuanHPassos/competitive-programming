#include<bits/stdc++.h>
using namespace std;
#define s second
#define f first
const int MAXN = 1e3+10;
vector<pair<int,int>> mov = {{1,0},{-1,0},{0,1},{0,-1}};
int caverna[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];
pair<int,int> fim;
pair<int,int> ini;
int n, m;
bool valid(int i, int j){
    return i>=0 and j>=0 and i<n and j<m and !vis[i][j] and caverna[i][j];
}
void bfs_ms(pair<int,int> s){
    queue<pair<int,int>> q;
    q.push(s); vis[s.f][s.s] = true;
    dist[s.f][s.s] = 1;
    while(!q.empty()){
        pair<int,int> u = q.front(); q.pop();
        for(auto v: mov){
            v.f += u.f; v.s += u.s;
            if(valid(v.f,v.s)){
                q.push(v); vis[v.f][v.s] = true; 
                dist[v.f][v.s] = dist[u.f][u.s] + 1;
            }
            if(v == fim) return;
        }
    }
    return;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> caverna[i][j];
            if(caverna[i][j] == 3) fim = {i,j};
            if(caverna[i][j] == 2) ini = {i,j};
        }
    }
    bfs_ms(ini);
    cout << dist[fim.f][fim.s];
}
