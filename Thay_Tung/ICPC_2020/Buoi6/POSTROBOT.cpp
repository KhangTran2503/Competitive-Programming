#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9) + 7;
vector<vector<int>> g;
vector<int> depth;
vector<vector<int>> binup;
vector<int> marked;
int High;
int n, m ;


void dfs(int u,int par,int dept){
	binup[u][0] = par;
	depth[u] = dept;
	for (int i = 1; i <= High; ++i)
		binup[u][i] = binup[binup[u][i - 1]][i - 1];
	
	int cnt_child = 0;
	for (int v: g[u])
		if (v != par){
			marked[v] = cnt_child++;
			dfs(v,u,dept + 1);
		}
}

vector<int> get_lca(int u,int v){
	bool sw = false;
	if (depth[u] < depth[v]) {
		sw = true;
		swap(u,v);
	}
	
	for (int i = High; i >= 0; --i)
		if (depth[u] - (1 << i) >= depth[v]) u = binup[u][i];
	
	if (u == v) return {u,-1,-1};
	
	for (int i = High; i >= 0; --i)
		if (binup[u][i] != binup[v][i]){
			u = binup[u][i];
			v = binup[v][i];
		}
	if (sw) swap(u,v);
	return {binup[u][0],u,v};
}



int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	g.resize(n);
	marked.resize(n);
	
	
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	
	High = ceil(log2(n));
	binup.assign(n,vector<int> (High + 1));
	depth.resize(n);
	dfs(0,0,0);
	
	vector<vector<pair<int,int>>> need_pass(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		vector<int> lca = get_lca(u,v);
		//cout << lca << ' ';
		if (v == lca[0]){
			cout << 0;
			return 0;
		}
		if (lca[1] != -1 && lca[2] != -1){
			//cout << marked[u] << ' ' << marked[v] << '\n';
			need_pass[lca[0]].emplace_back(marked[lca[1]],marked[lca[2]]);
		}
	}
	
	//for (int x: marked) cout << x << ' ';
	//cout << '\n';

	ll ans = 1;
	vector<int> mask(12);
	vector<ll> dp(1 << 12);
	for (int u = 0; u < n; ++u){
		int deg = (int)g[u].size();
		if (u) deg--;
		int max_mask = (1 << deg);
		//fill_n(mask.begin(),deg,0);
		//fill_n(dp.begin(),max_mask,0);
		for (int i = 0; i < deg; ++i) mask[i] = 0;
		
		for (auto e: need_pass[u]) mask[e.first] |= (1 << e.second);
		dp[0] = 1;
		
		for (int msk = 1; msk < max_mask; ++msk){
			dp[msk] = 0;
			for (int v = 0; v < deg; ++v)
				if (((msk >> v) & 1) && ((mask[v] & msk) == 0))
					dp[msk] = (dp[msk] + dp[msk^(1 << v)]) % MOD;
		}
		ans = (ans*dp[max_mask - 1]) % MOD;
	}
	cout << ans;
	
	return 0;
}
