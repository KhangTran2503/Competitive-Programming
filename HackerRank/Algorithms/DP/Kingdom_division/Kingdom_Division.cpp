/*	2020-12-03	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
const ll MOD = (ll)(1e9) + 7;
vector<vector<int>> g;
vector<vector<ll>> dp;
int n;

// dp[u][0] is number configure color[u] == color[par[u]]
// dp[u][1] is number configure color[u] != color[par[u]]

void dfs(int u,int par){
	dp[u][0] = dp[u][1] = 1;
	ll neg = 1;
	for (int &v: g[u]){
		if (v == par) continue;
		dfs(v,u);
		dp[u][0] = (dp[u][0]*(dp[v][0] + dp[v][1]) % MOD) % MOD;
		neg = (neg*dp[v][1]) % MOD;
	}
	ll all = dp[u][0];
	dp[u][1] *= (all - neg + MOD) % MOD;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	g.resize(n + 1);
	dp.assign(n + 1,vector<ll> (2,0));
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1,0);
	cout << (2LL*dp[1][1]) % MOD;
	return 0;
}