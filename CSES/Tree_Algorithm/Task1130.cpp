/*	2020-12-19	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
vector<vector<int>> g;
vector<vector<int>> dp;
int n;

void dfs(int u,int p){
	dp[u][0] = dp[u][1] = 0;
	for (int v: g[u]){
		if (v == p) continue;
		dfs(v,u);
		dp[u][0] += max(dp[v][0],dp[v][1]);
	}
	
	for (int v: g[u]){
		if (v == p) continue;
		dp[u][1] = max(dp[u][1],dp[u][0]- dp[v][1] + dp[v][0] + 1);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	g.resize(n + 1);
	dp.assign(n + 1,vector<int> (2,0));
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(1,0);
	cout << max(dp[1][0],dp[1][1]);
	return 0;
}