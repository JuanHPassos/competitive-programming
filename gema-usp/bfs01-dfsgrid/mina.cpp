#include<bits/stdc++.h>
using namespace std;
int n;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e2+10;
#define f first
#define s second
int ans[MAXN][MAXN];
int mina[MAXN][MAXN];
vector<pair<int,int>> mov = {{1,0}, {-1,0}, {0,1}, {0,-1}};
bool valid(int i, int j){
    return i>=0 and j>=0 and i<n and j<n;
}
void bfs(pair<int,int> p){
    memset(ans, INF, sizeof(ans));
    deque<pair<int,int>> q;
    q.push_front(p); ans[0][0] = 0;
    while(!q.empty()){
       pair<int,int> u = q.front(); q.pop_front();
       for(auto v: mov){
            v.f += u.f; v.s += u.s;
            if(valid(v.f, v.s) && ans[u.f][u.s] + mina[v.f][v.s] < ans[v.f][v.s] ){
                ans[v.f][v.s] = ans[u.f][u.s] + mina[v.f][v.s];
                if(mina[v.f][v.s]) q.push_back(v);
                else q.push_front(v);
            }
       } 
    }
}

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> mina[i][j];
        }
    }
    pair<int,int> p = {0, 0};
    bfs(p);
    cout << ans[n-1][n-1];
    return 0;
}
