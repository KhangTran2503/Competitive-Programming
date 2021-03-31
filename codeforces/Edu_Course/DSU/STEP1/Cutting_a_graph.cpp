#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
using namespace std;
typedef tuple<int,int,int> tup;

struct DSU{
	vector<int> par;
	vector<int> rank;
	DSU(int sz){
		par.assign(sz + 1,-1);
		rank.assign(sz + 1,0);
	}
	
	int FindSet(int u){
		return (par[u] < 0) ? u : par[u] = FindSet(par[u]);
	}
	
	bool isSame(int u,int v){
		return FindSet(u) == FindSet(v);
	}
	
	void Union(int u,int v){
		u = FindSet(u);
		v = FindSet(v);
		if (u == v) return;
		if (rank[u] == rank[v]) rank[u]++;
		if (rank[u] > rank[v]){
			par[v] = u;
		}
		else par[u] = v;
	}
};

set<pair<int,int>> edges;
vector<tup> query;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u,v);
		edges.insert({u,v});
	}
	DSU dsu(n);
	string s;
	while (k--){
		int u, v;
		cin >> s >> u >> v;
		if (u > v) swap(u,v);
		if (s == "cut"){
			edges.erase(edges.find({u,v}));
			query.emplace_back(0,u,v);
		}
		else query.emplace_back(1,u,v);
	}
	
	if (!edges.empty()){
		for (auto e: edges)
			dsu.Union(e.first,e.second);
	}
	
	reverse(all(query));
	
	vector<bool> ans;
	for (tup q: query){
		int tp, u, v;
		tie(tp,u,v) = q;
		if (tp) ans.emplace_back(dsu.isSame(u,v));
		else dsu.Union(u,v);
	}  
	
	reverse(all(ans));
	for (auto x: ans)
		(x) ? cout << "YES\n" : cout << "NO\n"; 
	return 0;
}
