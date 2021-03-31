#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod = (ll)(1e9) + 7;
vector<vector<int>> g;
vector<vector<ll>> dp;
int n;
//  goi dp[u][0,1] la xet cay goc u dinh u to mau (0,1)
// gia su ghep v vao
void add(ll &a,ll b){
    a += b;
    a %= Mod;
}

void mul(ll &a,ll b){
    a = ((a% Mod) * (b % Mod)) % Mod;
}
void dfs(int u,int p){
    dp[u][0] = dp[u][1] = 1;
    for (int v: g[u]){
        if (v == p) continue;
        dfs(v,u);
        mul(dp[u][0],(dp[v][1] + dp[v][0]) % Mod);
        mul(dp[u][1],dp[v][0]);
    }

    
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;

    g.resize(n);
    dp.resize(n, vector<ll> (2,0));
    for (int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    dfs(0,-1);
    cout << (dp[0][1] + dp[0][0]) % Mod;
    return 0;
}