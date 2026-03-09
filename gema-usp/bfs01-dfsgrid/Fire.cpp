#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+10;
#define f first
#define s second
const int INF = 0x3f3f3f3f;
int n, m;
int dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
char mapa[MAXN][MAXN];
vector<pair<int, int>> mov = {{-1, 0}, {1,0}, {0, -1}, {0, 1}};//Cima, Baixo, ESQUERDA, DIREITA;
bool valid(int i, int j){
    if(i >= 0 and j>= 0 and i<n and j<m and !vis[i][j] and mapa[i][j] != '#') return true;
    return false;
}

void bfsfogo(vector<pair<int,int>> fire){
    memset(vis, 0, sizeof(vis));
    memset(dist, INF, sizeof(dist));
    queue<pair<int,int>> q;
    for(auto ev : fire){
        q.push(ev); vis[ev.f][ev.s] = true; dist[ev.f][ev.s] = 0; 
    }
    while(!q.empty()){
        auto u = q.front(); q.pop();
        for(auto v : mov){
            v.f += u.f; v.s += u.s;
            if(valid(v.f, v.s)){
                q.push(v); vis[v.f][v.s] = true;
                dist[v.f][v.s] = dist[u.f][u.s] + 1;
            }
        }
    }
}

int bfs(pair<int,int> ini){
    memset(vis, 0, sizeof(vis));
    queue<pair<int,int>> q;
    q.push(ini); vis[ini.f][ini.s] = 1; dist[ini.f][ini.s] = 0;
    while(!q.empty()){
        pair<int,int> u = q.front(); q.pop();
        if(u.f == 0 || u.f == n-1 || u.s == 0 || u.s == m-1) return dist[u.f][u.s] + 1;
        for(auto v: mov){
            v.f += u.f; v.s += u.s;
            if(valid(v.f, v.s) && dist[u.f][u.s]+1 < dist[v.f][v.s]){
                q.push(v); vis[v.f][v.s] = true; dist[v.f][v.s] = dist[u.f][u.s] + 1;
            }
        }
    }
    return -1;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> n;
        vector<pair<int,int>> fire;
        pair<int,int> ini;
        for(int i = 0; i<n; i++) for(int j = 0; j<m; j++){ cin >> mapa[i][j];}
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++){
                if(mapa[i][j] == '*') fire.push_back({i, j});
                else if(mapa[i][j] == '@') ini = {i, j};
            }
        bfsfogo(fire);
        int ans = bfs(ini);
        if(ans == -1) cout << "IMPOSSIBLE" << "\n";
        else cout << ans << "\n";
    }
    return 0;
}
