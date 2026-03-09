#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+10;
#define f first
#define s second
int n, m;
vector<string> lab(MAXN);
bool vis[MAXN][MAXN];
pair<int, int> pai[MAXN][MAXN];
char ans[MAXN][MAXN];
pair<int, int> u;
pair<int, int> B;
vector<char> path;
int tam = 0;
vector<pair<int,int>> mov = {{1,0}, {-1,0}, {0,1}, {0,-1}};
bool valid(int i, int j){
    return i>= 0 and j>= 0 and i<n and j<m and !vis[i][j] and lab[i][j] != '#';
}
pair<int,int> bfs(pair<int,int> z){
    queue<pair<int,int>> q;
    q.push(z); vis[z.f][z.s] = true;
    while(!q.empty()){
        pair<int,int> v = q.front(); q.pop();
        int cont = 0;
        for(auto w: mov){
            int newi = v.f+ w.f, newj = v.s + w.s;
            if(valid(newi, newj)){
                vis[newi][newj] = true; pai[newi][newj] = v; q.push({newi, newj});
                if(cont == 0) ans[newi][newj] = 'D'; 
                else if(cont == 1) ans[newi][newj] = 'U'; 
                else if(cont == 2) ans[newi][newj] = 'R'; 
                else if(cont == 3) ans[newi][newj] = 'L'; 
                if(lab[newi][newj] == 'B') return {newi, newj};
            }
            cont++;
        }
    } 
    return {-1,-1};
}
void encontrar(pair<int,int> b){
    if(b == u) return;
    path.push_back(ans[b.f][b.s]);
    tam++;
    encontrar(pai[b.f][b.s]);
}
int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++) cin >> lab[i];
    for(int i = 0; i<n; i++) 
        for(int j = 0; j<m; j++){
            if(lab[i][j] == 'A'){ 
                u = {i ,j};
                B = bfs(u);
            }
        }
    if(B.f == -1){cout << "NO"; return 0;}
    encontrar(B);
    cout << "YES" << "\n";
    cout << tam << "\n";
    for(int i = tam-1; i>=0; i--){cout << path[i];}
    return 0;
}
