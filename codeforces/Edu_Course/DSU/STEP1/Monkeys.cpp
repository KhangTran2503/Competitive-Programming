#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int> par;
	vector<int> rank;
	vector<vector<int>> children;
	DSU(int sz){
		par.assign(sz + 1,-1);
		//rank.assign(sz + 1,0);
		children.resize(sz + 1);
		for (int u = 1; u <= sz; ++u) children[u].emplace_back(u);
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
		//if (rank[u] == rank[v]) rank[u]++;
		if ((int)children[u].size() > (int)children[v].size()) swap(u,v);
		//move(children[u].begin(),children[u].end(),back_inserter(children[v]));
		for (int x: children[u]) children[v].emplace_back(x);
		par[v] += par[u];
		par[u] = v;
		//return true;
	}
};

multiset<pair<int,int>> edges;
vector<vector<int>> g;

int n, m;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	g.resize(n + 1,vector<int> (2));
	for (int i = 1; i <= n; i++){
		int li, ri;
		int par = i;
		cin >> li >> ri;
		g[i][0] = li;
		g[i][1] = ri;
		if (li != -1){
			if (par > li) swap(par,li);
			edges.insert({par,li});
		}
		
		par = i;
		if (ri != -1){
			if (par > ri) swap(par,ri);
			edges.insert({par,ri});
		}
		
	}
	//for (auto e: edges) {
		//cout << e.first << ' ' << e.second << '\n';
		////dsu.Union(e.first,e.second);
	//}
	//cout << "************************\n";
	vector<pair<int,int>> event;
	for (int i = 0; i < m; ++i){
		int u, v;
		cin >> u >> v;
		v--;
		v = g[u][v];
		
		event.emplace_back(u,v);
		if (u > v) swap(u,v);
		//cout << u << ' ' << v << '\n';
		edges.erase(edges.find({u,v}));
	}
	
	//cout << "############################\n";
	DSU dsu(n);
	
	for (auto e: edges) {
		//cout << e.first << ' ' << e.second << '\n';
		dsu.Union(e.first,e.second);
	}
	
	vector<int> ans(n + 1,-1);
	
	for (int i = m - 1; i >= 0; i--){
		pair<int,int> uv = event[i];
		//cout << uv.first << ' ' << uv.second << '\n';
		if (dsu.isSame(uv.first,uv.second)) continue;
		if (dsu.isSame(uv.second,1)){
			int u = dsu.FindSet(uv.first);
			//cout << 1 << '\n';
			for (int child: dsu.children[u]) ans[child] = i;
		}
		else if (dsu.isSame(uv.first,1)){
			//out << 2 << '\n';
			int v = dsu.FindSet(uv.second);
			for (int child: dsu.children[v]) ans[child] = i;
		}
		dsu.Union(uv.first,uv.second);
	}
	
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
	
	return 0;
}
