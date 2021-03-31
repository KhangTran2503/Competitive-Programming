#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int> par;
	vector<int> dis;
	DSU(int sz){
		par.assign(sz + 1,-1);
		dis.assign(sz + 1,0);
	}
	
	int FindSet(int u){
		if (par[u] < 0) return u;
		int t = FindSet(par[u]);
		dis[u] += dis[par[u]];
		return par[u] = t;
	}
	
	void Union(int u,int v){
		u = FindSet(u);
		v = FindSet(v);
		if (u == v) return;
		//if (par[u] < par[v]) swap(u,v);
		par[v] += par[u];
		par[u] = v;
		dis[u] = 1;
	}
	
	int get_ans(int u){
		FindSet(u);
		return dis[u];
	}
};


int n, m;
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	DSU dsu(n);
	while (m--){
		int type;
		cin >> type;
		if (type == 1){
			int a, b;
			cin >> a >> b;
			dsu.Union(a,b);
		}
		else{
			int c;
			cin >> c;
			cout << dsu.get_ans(c) << '\n';
		}
	}
	return 0;
}
