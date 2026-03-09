#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
vector<vector<int>> g(MAXN);
vector<bool> vis(MAXN), team(MAXN);
bool pos;
void bfs(int v){
    queue<int> q; q.push(v);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto d: g[u]){
            if(!vis[d]){
                team[d] = !team[u]; vis[d] = true; q.push(d);
            }else{
                if(team[d] == team[u]) pos = false;
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    pos = true;
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            vis[i] = true;
            bfs(i);
        }
    }
    if(pos) for(int i = 1; i<=n; i++) cout << team[i]+1 << " ";
    else cout << "IMPOSSIBLE";
    return 0;
}
