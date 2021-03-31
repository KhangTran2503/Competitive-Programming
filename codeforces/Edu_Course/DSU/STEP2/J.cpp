#include <bits/stdc++.h>
using namespace std;
int n, m;

struct DSU{
	vector<int> par;
	vector<int> parity;
	DSU(int sz){
		par.assign(sz + 1,-1);
		parity.assign(sz + 1,0);
	}
	
	int FindSet(int u){
		if (par[u] < 0) return u;
		int t = FindSet(par[u]);
		parity[u] ^= parity[par[u]];
		return par[u] = t;
	}
	
	bool Union(int u,int v){
		int U = FindSet(u);
		int V = FindSet(v);
		if (U == V){
			if (parity[u] == parity[v]) return false;
			return true;
		}
		
		if (par[U] < par[V]) swap(U,V);
		par[V] += par[U];
		par[U] = V;
		parity[U] = parity[u]^parity[v]^1;
		return true;
	}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int ans = -1;
	DSU dsu(n);
	for (int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		if (!dsu.Union(u,v) && ans == -1) ans = i;
	}
	cout << ans << '\n';
	return 0;
}