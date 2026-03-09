#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
vector<set<int>> adj(MAXN);
int n, m, t, a, b;

int main(){
    cin >> n >> m;
    for(int i = 0; i<m ; i++){
        cin >> t >> a >> b;
        if(t == 1){
            adj[a].insert(b);
            adj[b].insert(a);}
        else
            if(adj[a].find(b) != adj[a].end())
                cout << 1 << '\n';
            else 
                cout << 0 << '\n';
    }
    return 0;
}
