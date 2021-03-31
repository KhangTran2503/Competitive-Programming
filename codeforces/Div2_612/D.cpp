// O(n^2)
// combine all node child , then insert u into position c[u]-th 
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> c;
int root, n;

vector<int> dfs(int u){
    vector<int> combine;
    for (int v: g[u]){
        vector<int> child = dfs(v);
        for (int z: child) combine.emplace_back(z); 
    }
    if (c[u] > combine.size()){
        cout << "NO";
        exit(0);
    }

    combine.insert(combine.begin() + c[u],u);
    return combine;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    g.resize(n + 1);
    c.resize(n + 1);
    for (int i = 1; i <= n; i++){
        int p;
        cin >> p >> c[i];
        if (!p) root = i;
        else g[p].emplace_back(i);
    }

    vector<int> order = dfs(root);
    vector<int> ans(n + 1);
    for (int i = 0; i < order.size(); i++)
        ans[order[i]] = i + 1;
    cout << "YES\n";
    for (int i = 1; i < ans.size(); i++) cout << ans[i] << ' ';
    return 0;
}