#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int> par1;
	vector<int> par2;
	DSU(int sz){
		par1.resize(sz + 1,-1);
		par2.resize(sz + 1);
		iota(par2.begin(),par2.end(),0);
	}
	
	int FindSet1(int u){
		return (par1[u] < 0) ? u : par1[u] = FindSet1(par1[u]);
	}
	int FindSet2(int u){
		return (par2[u] == u) ? u : par2[u] = FindSet2(par2[u]);
	}
	
	int isSame1(int u,int v){
		return FindSet1(u) == FindSet1(v);
	}
	
	int isSame2(int u,int v){
		return FindSet2(u) == FindSet2(v);
	}
	
	void Union1(int u,int v){
		u = FindSet1(u);
		v = FindSet1(v);
		if (u == v) return;
		if (par1[u] < par1[v]) swap(u,v);
		par1[v] += par1[u];
		par1[u] = v;
	}
	
	void Union2(int u,int v){
		u = FindSet2(u);
		v = FindSet2(v);
		if (u == v) return;
		par2[u] = v;
	}
};
int n, q;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	DSU dsu(n + 2);
	while (q--){
		int type, u, v;
		cin >> type >> u >> v;
		if (type == 3){
			cout << ((dsu.isSame1(u,v)) ? "YES\n" : "NO\n");
		}
		else if (type == 1){
			dsu.Union1(u,v);
		}
		else {
			for (int l = dsu.FindSet2(u); l < v; l = dsu.FindSet2(l)){
				dsu.Union2(l,l + 1);
				dsu.Union1(l,l + 1);
			}
			
		}
	}
	
	return 0;
}	
