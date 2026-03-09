#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e3;
const int INF = 0x3f3f3f3f;
vector<vector<int>> adj(MAXN);
int pai[MAXN];
int dist[MAXN];
int n, m, ans = INF;
void bfs(int s){
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    pai[s] = s;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v: adj[u]){
            if(dist[v] == INF){
                pai[v] = u; q.push(v); dist[v] = dist[u] + 1;
            }
            else if(pai[u] != v && pai[v] != u){
                ans = min(ans, dist[v] + dist[u] + 1);
            }
        }
    }
}
 
int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i<=n; i++){
        memset(pai, -1, sizeof(pai));
        memset(dist, INF, sizeof(dist));
        bfs(i);
    }
    if(ans == INF) cout << -1;
    else cout << ans;
    
    return 0;
}
