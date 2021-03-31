#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

struct DSU_with_rollback{
	struct Data{
		int Time, u, paru, v, parv;
		Data(int _Time = 0,int _u = 0,int _paru  = 0,int _v = 0,int _parv = 0): Time(_Time), u(_u),paru(_paru), v(_v), parv(_parv){}
	};
	
	vector<int> par;
	vector<Data> change;
	int checkpoint;
	int size;
	int components;
	
	DSU_with_rollback(int sz){
		par.assign(sz + 1,-1);
		components = sz;
		size = sz;
		checkpoint = 0;
	}
	
	
	void reset(){
		par.assign(size + 1,-1);
		components = size;
		checkpoint = 0;
		change.clear();
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
			change.push_back(Data(checkpoint,u,par[u],v,par[v]));
			par[v] += par[u];
			par[u] = v;
		}
	}
	
	void snapshot(){
		checkpoint++;
	}	
	
	void rollback(){
		checkpoint--;
		while (!change.empty() && change.back().Time > checkpoint){
			int u = change.back().u;
			int pu = change.back().paru;
			int v = change.back().v;
			int pv = change.back().parv;
			change.pop_back();
			par[u] = pu;
			par[v] = pv;
			components++;
		}
		
	}
	

};

int Block_size;

struct Query{
	int l, r, idx;
	Query(int _l = 0,int _r = 0,int _idx = 0): l(_l),r(_r),idx(_idx){}
	bool operator < (const Query &other) const{
		return make_pair(l/Block_size,r) < make_pair(other.l/Block_size,other.r);
	}

};



vector<ii> edges;
int n, m, k;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	edges.resize(m);
	for (int i = 0; i < m; i++) cin >> edges[i].first >> edges[i].second;
	
	Block_size = (int)sqrt(m);
	
	vector<Query> queries1;
	vector<Query> queries2;
	cin >> k;
	for (int i = 0; i < k; i++){
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (r - l + 1 <= Block_size) queries1.push_back(Query(l,r,i));
		else queries2.push_back(Query(l,r,i));
	}
	
	sort(queries2.begin(),queries2.end());
	vector<int> answer(k);
	
	DSU_with_rollback dsu(n);
	// calc with r - l + 1 <= Block_size
	for (Query q: queries1){
		dsu.snapshot();
		for (int i = q.l ; i <= q.r; i++) dsu.Union(edges[i].first,edges[i].second);
		answer[q.idx] = dsu.components;
		dsu.rollback();
	}
	
	
	
	// Else
	int last_block = -1;
	
	int cur_l = -1;
	int cur_r = -1;
	for (Query q: queries2){

		int cur_block = q.l/Block_size;
		if (cur_block != last_block){
			dsu.reset();
			cur_l = (cur_block + 1)*Block_size;
			cur_r = q.r;
			for (int i = cur_l; i <= cur_r; i++)
				dsu.Union(edges[i].first,edges[i].second);
		}
		last_block = cur_block;
		while (cur_r < q.r){
			cur_r++;
			dsu.Union(edges[cur_r].first,edges[cur_r].second);
		}
		
		dsu.snapshot();
		for (int i = q.l; i < cur_l; i++) dsu.Union(edges[i].first,edges[i].second);
		answer[q.idx] = dsu.components;
		dsu.rollback();
		
	}
	
	for (int &x: answer) cout << x << '\n';
	return 0;
}
