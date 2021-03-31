#include <bits/stdc++.h>
using namespace std;

struct DSU_with_rollback{
	struct Data{
		int Time, u, paru, v, parv;
		Data(int _Time = 0,int _u = 0,int _paru  = 0,int _v = 0,int _parv = 0): Time(_Time), u(_u),paru(_paru), v(_v), parv(_parv){}
	};
	
	vector<int> par;
	stack<Data> change;
	int checkpoint  = 0;
	
	int components;
	
	DSU_with_rollback(int sz){
		par.assign(sz + 1,-1);
		components = sz;
	}
	
	int FindSet(int u){
		return (par[u] < 0) ? u: FindSet(par[u]);
	}
	
	void Union(int u,int v){
		u = FindSet(u);
		v = FindSet(v);
		if (u != v){
			components--;
			if (par[u] < par[v]) swap(u,v);
			change.push(Data(checkpoint,u,par[u],v,par[v]));
			par[v] += par[u];
			par[u] = v;
		}
		cout << components << '\n';
		
	}
	
	void persist(){
		checkpoint++;
	}	
	
	void rollback(){
		checkpoint--;
		while (!change.empty() && change.top().Time > checkpoint){
			int u = change.top().u;
			int pu = change.top().paru;
			int v = change.top().v;
			int pv = change.top().parv;
			change.pop();
			par[u] = pu;
			par[v] = pv;
			components++;
		}
		cout << components << '\n';
	}
	

};


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	DSU_with_rollback dsu(n);
	while (m--){
		string s;
		cin >> s;
		if (s == "persist"){
			//cerr << "persist\n";
			dsu.persist();
		}
		else if (s == "union"){
			int u, v;
			cin >> u >> v;
			//cerr << "Edge: " << u << ' ' << v << '\n';
			dsu.Union(u,v);
		}
		else dsu.rollback();
	}
	return 0;
}