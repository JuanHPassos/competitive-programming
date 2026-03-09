#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int MAXN = 5e2+10;
vector<pair<int,int>> mov = {{1,0},{0,1},{0,-1}};
vector<string> mat(MAXN);
bool vis[MAXN][MAXN];
int n, m;
bool valid(int i, int j){
    return i>=0 && j>=0 && i<n && j<m && !vis[i][j] && mat[i][j] == '.';
}
void bfs_ms(pair<int,int> s){
    queue<pair<int,int>> q;
    q.push(s); vis[s.f][s.s] = true;
    while(!q.empty()){
        pair<int,int> u = q.front(); q.pop();
        int cont = 0;
        for(auto v: mov){
            v.f += u.f; v.s += u.s;
            if(valid(v.f, v.s)){
                if((cont == 0 && mat[v.f-1][v.s] == 'o') || (cont == 1 && mat[v.f][v.s-1] == 'o' && mat[v.f+1][v.s-1] == '#')||
                (cont == 2 && mat[v.f][v.s+1] == 'o' && mat[v.f+1][v.s+1] == '#')){
                q.push(v); mat[v.f][v.s] = 'o'; vis[v.f][v.s] = true;}
            }
            cont++;
        }
    }
}
int main(){
    cin >> n >> m; 
    for(int i = 0; i<n; i++) cin >> mat[i];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m;j++){
           if(mat[i][j] == 'o') bfs_ms({i, j});
        }
    }
    for(int i = 0; i<n; i++){ cout << mat[i] << "\n";}
    return 0;
}
