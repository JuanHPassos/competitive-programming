#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
vector<int> adj[MAXN];
vector<bool> vis(MAXN);
vector<int> roads(MAXN);
void dfs(int s){
    if(vis[s]) return;
    vis[s] = true;
    for(auto u: adj[s]) dfs(u);
}
 
 
int main(){
    int n, m, tamr = 0;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i<=n; i++){
        if(!vis[i]){ 
            roads[tamr] = i; 
            tamr++;
            dfs(i);}
    }
    cout << tamr-1 << '\n';
    for(int i = 0; i < tamr-1; i++){
        cout << roads[i] << " " << roads[i+1] << '\n';
    }
    return 0;
}
