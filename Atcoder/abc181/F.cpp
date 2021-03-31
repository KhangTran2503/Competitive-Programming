#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
vector<ii> p;
int n;


struct DSU{
	vector<int> par,rank;
	DSU(){};
	DSU(int sz){
		par.resize(sz);
		rank.resize(sz);
		iota(par.begin(),par.end(),0);
	}
	void set(int sz){
		par.resize(sz);
		rank.resize(sz);
		iota(par.begin(),par.end(),0);
	}
	void reset(){
		iota(par.begin(),par.end(),0);
		fill(rank.begin(),rank.end(),0);
	}
	bool isSame(int u,int v){
		return Get(u) == Get(v);
	}
	
	int Get(int u){return (par[u] == u) ? u : par[u] = Get(par[u]);};
	
	void Union(int u,int v){
		if (isSame(u,v)) return;
		int U = Get(u);
		int V = Get(v);
		if (rank[U] == rank[V]) rank[U]++;
		if (rank[U] > rank[V]) par[V] = U;
		else par[U] = V;
	}
};
DSU dsu;


double dis(ii u,ii v){
	return sqrt((u.first - v.first)*(u.first - v.first) + (u.second - v.second)*(u.second - v.second));
}

bool check(double r){
	dsu.reset();
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (dis(p[i],p[j]) <= r + r) dsu.Union(i,j);
	
	for (int i = 0; i < n; i++){
		if (dis(p[i],{p[i].first,100}) <= r + r) dsu.Union(i,n);
		if (dis(p[i],{p[i].first,-100}) <= r + r) dsu.Union(i,n + 1);
	}
	
	return !dsu.isSame(n,n + 1);
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	p.resize(n);
	for (auto &pi: p) cin >> pi.first >> pi.second;
	
	double low = 0, high = 100;
	
	dsu.set(n + 2);
	for (int iter = 0; iter < 100; iter++){
		double mid = (low + high)/2;
		if (check(mid)) low = mid;
		else high = mid;
	}
	
	cout << fixed << setprecision(10) << low;
	return 0;
}
