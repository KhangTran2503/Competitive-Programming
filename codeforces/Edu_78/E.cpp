#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<pair<int,int>> ans;
int n;
int maxR = 1;
// u - v1,v2,... vk
// duyet tu thang vk trc sao cho [lvk,rvk] ngan nhat
void dfs(int u,int p,int L){
    int numchild = int(g[u].size()) - int(p != -1);
    maxR += (numchild + 1);
    int R = maxR;
    ans[u] = make_pair(L,R);
    for (int v: g[u]){
        if (v == p) continue;
        R--;
        dfs(v,u,R);
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    g.resize(n);
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ans.resize(n);
    dfs(0,-1,1);
    //cout << "ans:\n";
    for (pair<int,int> x: ans) cout << x.first << ' ' << x.second << '\n';
    return 0;
}