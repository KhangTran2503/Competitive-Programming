#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int> par;
	vector<map<int,int>> cnt;
	DSU(int sz = 0){
		par.assign(sz,-1);
		cnt.resize(sz);
	}
	
	int Find(int u){
		return (par[u] < 0) ? u: par[u] = Find(par[u]);
	}
	
	bool same(int u,int v){
		return Find(u) == Find(v);
	}
	
	void Union(int u,int v){
		u = Find(u);
		v = Find(v);
		if (u == v) return;
		if ((int)cnt[u].size() < (int)cnt[v].size()) swap(u,v);
		for (auto it: cnt[v]) 
			cnt[u][it.first] += it.second;
		
		cnt[v].clear();
		par[u] += par[v];
		par[v] = u;
	}
	
	int get_ans(int u,int y){
		u = Find(u);
		return (cnt[u].find(y) != cnt[u].end()) ? cnt[u][y] : 0;
	}
};
int n, q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	DSU dsu(n);
	
	for (int i = 0; i < n; i++){
		int ci;
		cin >> ci;
		ci--;
		dsu.cnt[i][ci]++;	
	}
	
	while(q--){
		int c, x, y;
		cin >> c >> x >> y;
		x--, y--;
		if (c == 2){
			cout << dsu.get_ans(x,y) << '\n';
		}
		else dsu.Union(x,y);
	}
	return 0;
}
