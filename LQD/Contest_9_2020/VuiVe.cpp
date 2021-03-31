#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
vector<int> h;
vector<vector<int>> dp;
vector<vector<int>> g;
int n;

void dfs(int u,int par){
  
    if (g[u].size() == 1){
        dp[u][1] = h[u];
        dp[u][0] = -INF;
        return;
    }
    int tmp0 = 0;
    int tmp1 = 0;
    for (int v: g[u])
        if (v != par){
            dfs(v,u);
            tmp0 += max(0,max(dp[v][1],dp[v][0]));
            tmp1 += max(0,dp[v][0]);
        }
    dp[u][1] = tmp1 + h[u];
    if (tmp0 > 0) dp[u][0] = tmp0;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    h.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> h[i];

    dp.assign(n + 1,vector<int> (2,-INF));
    g.resize(n + 1);
    vector<int> in(n + 1);

    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        in[u]++;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int root = -1;
    for (int i = 1; i <= n; i++) 
        if (in[i] == 0){
            root = i;
            break;
        }
    
    //cout << root << '\n';
    dfs(root,-1);
    cout << dp[root][1];
    return 0;
}
