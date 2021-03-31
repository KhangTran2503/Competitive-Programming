#include <bits/stdc++.h>
#define oo int(1e9)
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e18);
int n, m;
vector<vector<int>> g;
vector<int> dp;
/// goi dp[u] la duong di dai nhat bat dau tai u
// DAG
int dfs(int u){
    if (dp[u] != -1) return dp[u];
    int ans = 0;
    for (int v: g[u])
        ans = max(ans, dfs(v) + 1);
    return dp[u] = ans;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; i++){
	    int u,v ;
	    cin >> u >> v;
	    u--; v--;
	    g[u].push_back(v);
	    //g[v].push_back(u);
	}
	int ans = 0;
	dp.resize(n);
	fill(all(dp),-1);
	for (int u = 0; u < n; u++)
	    ans = max(ans,dfs(u));
	cout << ans;
	return 0;
}
