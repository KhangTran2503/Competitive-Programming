#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<int>> g;
vector<int> color;
vector<int> par;
vector<bool> in_cycle;
int cycle_start,cycle_end;
int n;

bool find_cycle(int u,int p){
	color[u] = 1;
	for (int v: g[u]){
		if (v == p) continue;
		if (color[v] == 0){
			par[v] = u;
			if (find_cycle(v,u)) return true;
		}
		else if (color[v] == 1){
			cycle_start = v;
			cycle_end = u;
			return true;
		}
	}
	color[u] = 2;
	return false;
}

int dfs(int u,int p){
	int num_path = 1;
	for (int v: g[u]){
		if (v == p) continue;
		if (!in_cycle[v]) num_path += dfs(v,u); 
	}
	return num_path;
		
}


void solve(){
	cin >> n;
	g.assign(n,vector<int>());
	for (int i = 0; i < n; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	color.assign(n,0);
	par.assign(n,-1);
	cycle_start = -1;
	for (int u = 0; u < n; u++)
		if (color[u] == 0 && find_cycle(u,par[u])) break;
		
	vector<int> cycle;
	cycle.push_back(cycle_start);
	for (int u = cycle_end; u != cycle_start; u = par[u]) 
		cycle.push_back(u);
	
	
	in_cycle.assign(n,false);
	for (int u: cycle) in_cycle[u] = true;
	ll ans = (ll)n*(ll)(n - 1);
	
	//cout << cycle_start << ' ' << cycle_end << '\n';
	for (int u: cycle){
		//cout << u << ' ';
		ll num = (ll)dfs(u,-1);
		ans += (ll)num*(ll)(n - num);
	}
	//cout << '\n';
	ans >>= 1;
	cout << ans << '\n';
	
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}