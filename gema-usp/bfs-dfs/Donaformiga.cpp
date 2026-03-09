#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+10;
vector<int> adj[MAXN];
vector<int> alt(MAXN);
vector<bool> vis(MAXN);

void dfs(int s){
    if(vis[s]) return;
    vis[s] = true;
    for(auto u: adj[s]) dfs(u);
}
int main(){
    int s, t, p;
    cin >> s >> t >> p;
    for(int i = 1; i <=s; i++) cin >> alt[i];
    for(int l = 1; l<=t; l++){
        int i, j; cin >> i >> j;
        if(alt[i] > alt[j]) adj[i].push_back(j);
        else adj[j].push_back(i);
    }
    dfs(p);
    int ans = 0;
    for(int i = 1; i<=s; i++)
        if(vis[i] == 1) ans++;
    cout << ans-1 << endl;// o salão que ela começa, nao conta
    return 0;
}
