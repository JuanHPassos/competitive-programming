#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+10;
const int INF = 0x3f3f3f3f;
#define f first
#define s second
int n, m;
vector<string> mat(MAXN);
vector<pair<int,int>>  M;
pair<int,int>  A;
bool vis[MAXN][MAXN];
int dist[MAXN][MAXN];
char path[MAXN][MAXN];
pair<int,int> pai[MAXN][MAXN];
vector<pair<int,int>> mov = {{1,0},{-1,0},{0,1},{0,-1}};
bool valid(int i, int j){
    return i>= 0 && j>=0 && i<n && j<m && !vis[i][j] && mat[i][j] != '#';
}
void bfs_ms(){
    memset(dist, INF, sizeof(dist));
    queue<pair<int,int>> q;
    for(auto s: M){
        q.push(s); vis[s.f][s.s] = true; dist[s.f][s.s] = 0;
    } 
    while(!q.empty()){
        pair<int,int> u = q.front(); q.pop();
        for(auto v: mov){
            v.f += u.f; v.s += u.s;
            if(valid(v.f, v.s)){
                q.push(v); vis[v.f][v.s] = true; dist[v.f][v.s] = dist[u.f][u.s] + 1;
            }
        }
    }
}
pair<int,int> bfs(pair<int,int> s){
    memset(vis, false, sizeof(vis));
    queue<pair<int,int>> q;
    q.push(s); vis[s.f][s.s] = true; dist[s.f][s.s] = 0; pai[s.f][s.s] = s;
    while(!q.empty()){
        pair<int,int> u = q.front(); q.pop();
        if(u.f == 0 || u.s == 0 || u.f == n-1 || u.s == m-1) return u;
        int cont = 0;
        for(auto v: mov){
            v.f += u.f; v.s += u.s;
            if(valid(v.f, v.s) && dist[u.f][u.s] + 1 < dist[v.f][v.s]){
                q.push(v); dist[v.f][v.s] = dist[u.f][u.s] + 1; vis[v.f][v.s] = true; pai[v.f][v.s] = u;
                if(cont == 0) path[v.f][v.s] = 'D';
                else if(cont == 1) path[v.f][v.s] = 'U';
                else if(cont == 2) path[v.f][v.s] = 'R';
                else if(cont == 3) path[v.f][v.s] = 'L';
            }
            cont++;
        }
    }
    return {-1,-1};
}
 
int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++) cin >> mat[i];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == 'M') M.push_back({i,j});
            if(mat[i][j] == 'A') A = {i, j};
        }
    }
    bfs_ms();
    A = bfs(A);
    pair<int,int> L = A;
    vector<char> resp;
    for(int i = 0; i<dist[A.f][A.s]; i++){
        resp.push_back(path[L.f][L.s]);
        L = pai[L.f][L.s];
    }
    if(A.f == -1) cout << "NO";
    else{
        cout << "YES" << "\n";
        cout << dist[A.f][A.s] << "\n";
        for(int i = resp.size()-1; i>= 0; i--){
            cout << resp[i];
        }
    }
    return 0;
}
