#include <bits/stdc++.h>
using namespace std;

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


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	DSU dsu(n);
	while (m--){
		string s;
		cin >> s;
		int u, v;
		cin >> u >> v;
		if (s == "union") dsu.Union(u,v);
		else {
			(dsu.isSame(u,v)) ? cout << "YES\n" : cout << "NO\n" ;
		}
	}
	return 0;
}
