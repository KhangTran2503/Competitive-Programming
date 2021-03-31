#include <bits/stdc++.h>
using namespace std;
typedef tuple<int,int,int> tup;
typedef long long ll;
vector<tup> edges;

struct DSU{
	vector<int> par;
	DSU(int sz){
		par.assign(sz + 1,-1);
	}
	
	int FindSet(int u){return (par[u] < 0)? u : par[u] = FindSet(par[u]);}
	
	bool Union(int u,int v){
		u = FindSet(u);
		v = FindSet(v);
		if (u == v) return false;
		if (par[u] < par[v]) swap(u,v);
		par[v] += par[u];
		par[u] = v;
		return true;
	}
};


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		edges.emplace_back(w,u,v);
	}	
	
	DSU dsu(n);
	sort(edges.begin(),edges.end());
	
	ll ans = 0;
	for (tup e: edges){
		int u, v, w;
		tie(w,u,v) = e;
		if (dsu.Union(u,v)) ans = (ll)w;
	}
	
	cout << ans;
	return 0;
}
