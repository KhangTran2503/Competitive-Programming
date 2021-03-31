#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 7; 
vector<vector<int>> g;
vector<int> color;
vector<vector<ll>> dp;
int n;

void dfs(int u,int p){
    dp[u][color[u]] = 1;
    for (int v: g[u]){
        if (v == p) continue;
        dfs(v,u);
        dp[u][1] = (dp[u][1]*dp[v][0] + dp[u][0]*dp[v][1] + dp[u][1]*dp[v][1]) % Mod;
        dp[u][0] = (dp[u][0]*dp[v][0] + dp[u][0]*dp[v][1]) % Mod;
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    g.resize(n);
    color.resize(n);
    dp.resize(n + 1,vector<ll> (2));
    for (int i = 0; i < n - 1; i++){
        int x;
        cin >> x;
        g[x].push_back(i + 1);
        g[i + 1].push_back(x);
    }

    for (int i = 0; i < n; i++) cin >> color[i];
    dfs(0,-1);
    cout << dp[0][1];
    return 0;
}
