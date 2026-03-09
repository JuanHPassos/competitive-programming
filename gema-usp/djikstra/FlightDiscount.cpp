#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first
const int MAXN = 1e5+10;
const long long int INF = 1e18;
int n, m;
bool vis[MAXN];
vector<vector<pair<int, long long int>>> graph1(MAXN);
vector<vector<pair<int, long long int>>> graphn(MAXN);
vector<long long int> dist1(MAXN, INF);
vector<long long int> distn(MAXN, INF);
 
void dij1(){
    priority_queue<pair<long long int, int>> pq;
    dist1[1] = 0;
    pq.push({-0, 1});
    while(!pq.empty()){
        int u = pq.top().s;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto pv: graph1[u]){
            long long int v = pv.first, w = pv.second;
            if(dist1[u]+w < dist1[v]){
                dist1[v] = dist1[u]+w;
                pq.push({-dist1[v], v});
            }
        }
    }
}
void dij2(){
    memset(vis, false, sizeof(vis));
    priority_queue<pair<long long int, int>> pq;
    distn[n] = 0;
    pq.push({-0, n});
    while(!pq.empty()){
        int u = pq.top().s;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto pv: graphn[u]){
            long long int v = pv.first, w = pv.second;
            if(distn[u]+w < distn[v]){
                distn[v] = distn[u]+w;
                pq.push({-distn[v], v});
            }
        }
    }
}
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        graph1[a].push_back({b, w});
        graphn[b].push_back({a, w});
    }
    dij1();
    dij2();
    long long int ans = INF;
    for(int i = 1; i <= n; i++){
        for(auto u: graph1[i]){
            ans = min(ans , dist1[i] + distn[u.f] + u.s / 2); 
        }
    }
    cout << ans;
    return 0;
}
