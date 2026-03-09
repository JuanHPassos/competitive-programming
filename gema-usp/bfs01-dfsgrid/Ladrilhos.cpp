#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e2+10;
const int INF = 1e9;
#define f first
#define s second
int n, m, cont, ans = 0x3f3f3f3f;
int mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<pair<int,int>> mov = {{1,0},{-1,0},{0,1},{0,-1}};
bool valid(int i, int j){
    return i>= 0 && j>=0 && i<n && j<m && !vis[i][j];
}
void bfs_ms(pair<int,int> s){
    queue<pair<int,int>> q;
    cont = 1;
    q.push(s); vis[s.f][s.s] = true;
    while(!q.empty()){
        pair<int,int> u = q.front(); q.pop();
        for(auto v:mov){
            v.f += u.f; v.s += u.s;
            if(valid(v.f, v.s) && mat[v.f][v.s] == mat[s.f][s.s]){
                q.push(v); vis[v.f][v.s] = true; cont++;
            }
        }
    }
    ans = min(ans, cont);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<n; i++) for(int j = 0; j<m; j++) cin >> mat[i][j];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j]){
                bfs_ms({i, j});
            }
        }
    }
    cout << ans;
    return 0;
}
