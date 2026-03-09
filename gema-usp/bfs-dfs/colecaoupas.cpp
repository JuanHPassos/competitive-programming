#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> urso(n);
    set<int> ans;
    for(int i = 1; i<=n; i++) ans.insert(i);
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        urso[a-1].push_back(b);
        urso[b-1].push_back(a);
    }
    auto ptr = ans.end();
     while (ptr != ans.begin()) {
        --ptr;
        auto ptr1 = urso[*ptr - 1].begin();
        while (ptr1 != urso[*ptr - 1].end()) {
            ans.erase(*ptr1);
            ++ptr1;
        }
    }
    auto resp = ans.begin();
    cout << (int)ans.size() << "\n";
    for(int i = 1; i<=(int)ans.size(); i++){
        if((int)ans.size() > i) cout << *resp << " ";
        else cout << *resp << "\n";
        resp++;
    }
    return 0;
}
