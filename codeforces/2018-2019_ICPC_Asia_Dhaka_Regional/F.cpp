/*	2020-12-04	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9);
const int Maxbit = 10000;
int height;
int n;
vector<vector<int>> g;
vector<vector<int>> binup;
vector<int> depth;


void dfs(int u,int par){
	binup[u][0] = par;
	for (int i  = 1; i <= height; i++)
		binup[u][i] = binup[binup[u][i - 1]][i - 1];
	for (int v: g[u]){
		if (v == par) continue;
		depth[v] = depth[u] + 1;
		dfs(v,u);
	}
}

int lca(int u,int v){
	if (depth[u] < depth[v]) swap(u,v);
	for (int i = height; i >= 0; i--)
		if (depth[u] - (1 << i) >= depth[v]) u = binup[u][i];
	
	if (u == v) return u;
	
	for (int i = height; i >= 0; i--)
		if (binup[u][i] != binup[v][i]){
			u = binup[u][i];
			v = binup[v][i];
		}
	return binup[u][0];
}


void solve(int T){
	cin >> n;
	g.assign(n,vector<int> ());
	depth.assign(n,0);
	// lca
	height = 15;
	binup.assign(n,vector<int> (height + 1));
	
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	
	//pa.assgin(n,bitset<Maxbit>());
	
	dfs(0,0);
	vector<bitset<Maxbit>> pa(n);
	for (int u = 0; u < n; u++){
		int v = u;
		//cout << u << " ----------\n"; 
		do{
			//cout << v << '\n';
			pa[u][v] = 1;
			v = binup[v][0];
		}
		while (v != 0);
		pa[u][0] = 1;
		//cout << '\n';
	}
	
	int Q, K;
	cin >> Q;
	bitset<Maxbit> ans;
	cout << "Case " << T << ":\n"; 
	while (Q--){
		ans.set();
		//cout << ans << '\n';
		cin >> K;
		for (int i = 0; i < K; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			int r = lca(u,v);
			if (r == 0) ans &= ((pa[u] | pa[v]));
			else ans &= ((pa[u] | pa[v])^pa[binup[r][0]]);
			//cout << ans.count() << '\n';
		}
		cout << ans.count() << '\n';
	}
	
}
int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
	return 0;
}