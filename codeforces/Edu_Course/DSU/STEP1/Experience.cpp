#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DSU{
	vector<int> par;
	vector<int> sum;
	vector<int> extra;
	
	DSU(int sz){
		par.assign(sz + 1,-1);
		sum.assign(sz + 1,0);
		extra.assign(sz + 1,0);
	}
	
	int FindSet(int u){	
		return (par[u] < 0) ? u : FindSet(par[u]);
	}
	
	bool isSame(int u,int v){
		return FindSet(u) == FindSet(v);
	}
	
	void add(int u,int x){
		u = FindSet(u);
		sum[u] += (ll)x;
	}
	
	void Union(int u,int v){
		u = FindSet(u);
		v = FindSet(v);
		if (u == v) return;
		par[u] += par[v];
		//sum[u] += sum[v];
		par[v] = u;
		extra[v] = sum[u];
	}
	
	ll get_ans(int u){
		return (par[u] < 0)? sum[u] :sum[u] - extra[u] + get_ans(par[u]);
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
		if (s == "add"){
			cin >> u >> v;
			dsu.add(u,v);
		}
		else if (s == "join"){
			cin >> u >> v;
			dsu.Union(u,v);
		}
		else{
			cin >> u;
			cout << dsu.get_ans(u) << '\n';
		}
	}
	return 0;
}
