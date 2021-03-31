/*	2021-01-12	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const ll INF = (ll)(1e18) + 10;
vector<int> a;
vector<vector<int>> g;
vector<ll> dp;
int n, m;



int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	g.resize(n + 1);
	a.resize(n + 1);
	//vis.assign(n + 1,false);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	
	dp.assign(n + 1,INF);
		
	// DP DAG
	for (int u = 1; u <= n; u++){
		//cout << u << ' ';
		for (int v: g[u]) dp[v] = min(dp[v],min(dp[u],(ll)a[u]));
	}
	//cout << '\n';
	ll ans = -INF;
	for (int i = 1; i <= n; i++) ans = max(ans,(ll)(a[i] - dp[i])); 
		//cout << a[i] << ' ' << dp[i] << '\n';
	
	cout << ans; 
	return 0;
}