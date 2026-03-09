#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
const long long int INF = 1e18;
int n, m;
vector<vector<pair<int,int>>> adj(MAXN);
vector<long long int> dist(MAXN, INF);
vector<int> vis(MAXN);
vector<int> pai(MAXN);
void dij1(){
    priority_queue<pair<long long int,int>> pq;
    dist[1] = 0;
    pai[1] = 0;
    pq.push({-0,1});
    while(!pq.empty()){
        int a = (pq.top()).second;
        pq.pop();
        if(vis[a]) continue;
        vis[a] = true;
        for(auto u: adj[a]){
            int b = u.first;
            long long int w = u.second;
            if(dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
                pai[b] = a;
                pq.push({-dist[b], b});
            }
        }
    }
}
 
int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    dij1();
    if(!vis[n]){cout << -1; return 0;}
    vector<int> ans;
    int aux = n;
    while(aux != 0){
        ans.push_back(aux);
        aux = pai[aux];
    }
    for(int i = ans.size()-1; i>=0; i--){
        cout << ans[i] << " ";
    }
    return 0;
}
