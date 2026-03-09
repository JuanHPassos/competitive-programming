#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e4;
vector<vector<int>> graph(MAXN);
vector<int> ord(MAXN, 0);
vector<int> ans;
int n, m;
priority_queue<int> pq;
void bfs(){
    while(!pq.empty()){
        int u = -pq.top(); pq.pop();
        ans.push_back(u);
        for(auto v: graph[u]){
            ord[v]--;
            if(!ord[v]){
                pq.push(-v);
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i< m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        ord[b]++;
    }
    for(int i = 0; i<n; i++) if(!ord[i]) pq.push(-i); 
    bfs();
    if((int)(ans.size()) != n){ cout << "*"; return 0;}
    for(auto resp: ans){
        cout << resp << "\n";
    }
    return 0;
}
