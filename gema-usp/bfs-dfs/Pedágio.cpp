#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> est(51);
vector<bool> vis(51);
vector<int> ans;
vector<int> dist(51, 0);
int c, e, l, p;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dist[s] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : est[v]) {
            if (!vis[u]) {
                dist[u] = dist[v] + 1;
                if (p >= dist[u]) {
                    q.push(u);
                    vis[u] = true;
                    ans.push_back(u);
                }
            }
        }
    }
}

int main() {
    int n = 1;
    while (true) {
        cin >> c >> e >> l >> p;
        if (c == 0) break;
        for (int i = 0; i < 51; i++) {
            est[i].clear();
        }
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            est[a].push_back(b);
            est[b].push_back(a);
        }
        fill(vis.begin(), vis.end(), false);
        fill(dist.begin(), dist.end(), 0);
        ans.clear();
        bfs(l);
        sort(ans.begin(), ans.end());
        cout << "Teste " << n << "\n";
        for (auto u : ans) {
            cout << u << " ";
        }
        cout << "\n\n";
        n++;
    }
    return 0;
}
