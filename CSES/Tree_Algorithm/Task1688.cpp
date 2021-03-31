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
vector<vector<int>> binup;
vector<vector<int>> g;
vector<int> level;
int n, q;

void dfs(int u,int p){
	binup[u][0] = p;
	for (int k = 1; k < 20; k++) binup[u][k] = binup[binup[u][k - 1]][k - 1];
	for (int v: g[u]){
		if (v == p) continue;
		level[v] = level[u] + 1;
		dfs(v,u);
	}
}

int get_lca(int u,int v){
	if (level[u] < level[v]) swap(u,v);
	int delta = level[u] - level[v];
	for (int i = 19; i >= 0; --i)
		if ((delta >> i) & 1) u = binup[u][i];
	if (u == v) return u;
	for (int k = 19; k >= 0; k--)
		if (binup[u][k] != binup[v][k]){
			u = binup[u][k];
			v = binup[v][k];
		}
	return binup[u][0]; 
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q;
	g.resize(n + 1);
	level.resize(n + 1);
	binup.resize(n + 1,vector<int> (20,0));
	for (int i = 2; i <= n; i++){
		int x;
		cin >> x;
		g[x].push_back(i);
	}
	dfs(1,0);
	while (q--){
		int u, v;
		cin >> u >> v;
		cout << get_lca(u,v) << '\n';
	}
	return 0;
}