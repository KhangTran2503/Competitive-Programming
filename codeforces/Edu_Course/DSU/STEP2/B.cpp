#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);

struct DSU{
	vector<int> par;
	vector<int> rank;
	vector<int> max_e;
	DSU(int sz){
		par.assign(sz + 1,-1);
		rank.assign(sz + 1,0);
		max_e.resize(sz + 1);
		//min_e.resize(sz + 1);
		iota(max_e.begin(),max_e.end(),0);
		
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
			par[u] += par[v];
			par[v] = u;
			max_e[u] = max(max_e[u],max_e[v]);
			//min_e[u] = min(min_e[u],min_e[v]);
		}
		else {
			par[v] += par[u];
			par[u] = v;
			max_e[v] = max(max_e[v],max_e[u]);
			//min_e[v] = min(min_e[v],min_e[u]);
		}
	}
	
	int get_ans(int u){
		u = FindSet(u);
		return max_e[u];
	}
};


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> p(n);
	
	for (int &x: p) cin >> x;
	DSU dsu(n + n + 1);
	
	for (int x: p){
		int u = dsu.get_ans(x);
		cout << ((u > n) ? u - n : u) << ' ';
		dsu.Union(u,u + 1);
		if (u <= n) dsu.Union(u + n, u + n + 1);
		else dsu.Union(u - n,u + 1 - n);
	}
	return 0;
}
