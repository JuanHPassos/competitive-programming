#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
vector<int> adj[MAXN];
vector<bool> vis(MAXN);
vector<int> dist(MAXN, -1);
vector<int> pai(MAXN, -1);
 
 
void bfs(int s){
    queue<int> q;
    q.push(s); vis[s] = true;
    dist[s] = 0;
    pai[s] = s;
    while(!q.empty()){
        int frente = q.front(); q.pop();
        for(auto u : adj[frente]) if(!vis[u]){
            q.push(u); vis[u] = true;
            dist[u] = dist[frente] + 1;
            pai[u] = frente;}
        
    } 
 
}
vector<int> path(int v){
    vector<int> ret;
    if(!vis[v]) return ret; //se nao tiver sido visitado, retorna ret nulo;
    ret.push_back(v);
    while(pai[v] != v){ //v(vertice) != fonte;
        v = pai[v];
        ret.push_back(v);
    }
    reverse(ret.begin(), ret.end());
    return ret; 
}
 
 
 
int main(){
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    if(dist[n] == -1){
        cout << "IMPOSSIBLE";
        return 0;}
    cout << dist[n]+1 << '\n';// dist me da o numero de arestas, porem eu quero o de vertices, ent somo 1;
    vector<int> ans = path(n);
 
    for(auto u : ans) cout << u << " ";
    cout << endl;
}
