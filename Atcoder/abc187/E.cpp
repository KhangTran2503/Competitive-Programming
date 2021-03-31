/*	2021-01-05	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
vector<ii> edges;
vector<vector<int>> g;
vector<int> tin,tout;
vector<ll> sum;
int Time = 0;
int n;

void dfs(int u,int p){
	tin[u] = ++Time;
	for (int v: g[u]){
		if (v == p) continue;
		dfs(v,u);
	}
	tout[u] = Time;
}

bool is_ancestor(int u,int v){
	return (tin[u] <= tin[v] && tout[v] <= tout[u]);
}

void update(int u,int v,int delta){
	if (is_ancestor(u,v)){
		// update all tree delta
		sum[tin[1]] += delta;
		sum[tout[1] + 1] -= delta;
		// update tree root v -delta
		sum[tin[v]] -= delta;
		sum[tout[v] + 1] += delta;  
	}
	else {
		sum[tin[u]] += (ll)delta;
		sum[tout[u] + 1] -= (ll)delta;
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	g.resize(n + 1);
	tin.resize(n + 1);
	tout.resize(n + 1);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		edges.push_back({u,v});
	}
	
	dfs(1,0);
	sum.assign(Time + 2,0LL);
	
	int Q;
	cin >> Q;
	while (Q--){
		int t, e, x;
		cin >> t >> e >> x;
		e--;
		if (t == 1) update(edges[e].first,edges[e].second,x);
		else update(edges[e].second,edges[e].first,x);
	}
	
	for (int i = 1; i <= Time; i++) sum[i] += sum[i - 1];
	
	for (int i = 1; i <= n; i++) cout << sum[tin[i]] << '\n';
	return 0;
}