#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e2;
#define f first
#define s second
const int INF = 0x3f3f3f3f; 
int n, m;
vector<string> mat(MAXN);
int dist[MAXN][MAXN];
bool vis[MAXN][MAXN];
vector<pair<int,int>> mov = {{1,0}, {-1,0}, {0,1}, {0,-1}};
bool valid(int i, int j){
    return i>=0 and j>=0 and i<n and j<m and !vis[i][j];
}

void bfs_ms(vector<pair<int,int>> b){
    memset(dist, INF, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    queue<pair<int,int>> q;
    for(auto ev: b){
        q.push(ev); dist[ev.f][ev.s] = 0; vis[ev.f][ev.s] = true;
    }
    while(!q.empty()){
        auto u = q.front(); q.pop();
        for(auto v: mov){
            v.f += u.f; v.s += u.s;
            if(valid(v.f,v.s)){
                dist[v.f][v.s] = dist[u.f][u.s]+1; vis[v.f][v.s] = true;
                q.push(v);
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<pair<int,int>> b;
        cin >> n >> m;
        for(int i = 0; i<n; i++) cin >> mat[i]; 
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++){
                if(mat[i][j]-'0'){
                    b.push_back({i, j});
                } 
            }
        bfs_ms(b);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
