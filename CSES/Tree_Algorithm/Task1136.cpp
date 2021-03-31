/*	2020-12-20	*/
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
vector<int> level;
vector<int> cnt;
vector<vector<int>> g;
int n, m;

void dfs(int u,int p){
	binup[u][0] = p;
	for (int k = 1; k < 19; k++) binup[u][k] = binup[binup[u][k - 1]][k - 1];
	for (int v: g[u]){
		if (v == p) continue;
		level[v] = level[u] + 1;
		dfs(v,u);
	}
}

int get_lca(int u,int v){
	if (level[u] < level[v]) swap(u,v);
	int delta = level[u] - level[v];
	for (int k = 18; k >= 0; k--)
		if ((delta >> k) & 1) u = binup[u][k];
	
	if (u == v) return u;
	for (int k = 18; k >= 0; k--)
		if (binup[u][k] != binup[v][k]){
			u = binup[u][k];
			v = binup[v][k];
		}
	return binup[u][0];
}

void Up(int u,int p){
	for (int v: g[u]){
		if (v == p) continue;
		Up(v,u);
		cnt[u] += cnt[v];
	}
}

/*
	cnt[u] -> increasing 1 all vertex u -> root
*/
int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	g.resize(n + 1);
	binup.assign(n + 1,vector<int> (19,0));
	cnt.resize(n + 1);
	level.resize(n + 1);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	//return 0;
	while (m--){
		int u, v;
		cin >> u >> v;
		int lca = get_lca(u,v);
		//cout << lca << '\n';
		cnt[u]++;
		cnt[v]++;
		cnt[lca]--;
		cnt[binup[lca][0]]--;
	}
	
	//for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';
	//cout << '\n';
	Up(1,0);
	for (int i = 1; i <= n; i++) cout << cnt[i] << ' ';
	
	return 0;
}