#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+10;
vector<vector<int>> adj(MAXN);
bool vis[MAXN];
int dist[MAXN];

void bfs(int s){
    queue<int> q;
    q.push(s); vis[s] = true; dist[s] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v: adj[u]){
            if(!vis[v]){
                q.push(v); vis[v] = true; dist[v] = dist[u] + 1;
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    set<string> ord;
    vector<string> pal;
    map<string, int> acess;
    for(int i =0; i<n; i++){
        string a, b;
        cin >> a >> b;
        if(ord.find(a) == ord.end()){
            ord.insert(a);
            acess[a] = pal.size();
            pal.push_back(a);
        }
        if(ord.find(b) == ord.end()){
            ord.insert(b);
            acess[b] = pal.size();
            pal.push_back(b);
        }
        adj[acess[a]].push_back(acess[b]);     
    }
    auto ptr1 = ord.begin();
    auto ptr2= ord.begin();
    ptr2++;
    for(int i = 0; i<(int)(ord.size())-1; i++){
        adj[acess[*ptr1]].push_back(acess[*ptr2]);
        adj[acess[*ptr2]].push_back(acess[*ptr1]);
        ptr1++;
        ptr2++;
    }
    string a, b;
    cin >> a >> b;
    bfs(acess[a]);
    cout << dist[acess[b]];
    return 0;
}
