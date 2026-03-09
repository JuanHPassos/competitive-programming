#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+10;
vector<int> adj[MAXN];
vector<bool> vis(MAXN);
int n, m;
void bfs(int s){
    queue<int> q;
    q.push(s); vis[s] = true;
    while(!q.empty()){
        int frente = q.front(); q.pop();
        for(auto u: adj[frente]){
            if(!vis[u]){q.push(u); vis[u] = true;}
        }
    
    }
}

int main(){
    int cont = 0;
    cin >> n >> m;
    for(int l = 0; l<m; l++){
        int i, j;
        cin >> i >> j;
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    for(int i = 1; i<=n; i++)
        if(!vis[i]){ cont++; bfs(i);}
    cout << cont;
    return 0;
}
