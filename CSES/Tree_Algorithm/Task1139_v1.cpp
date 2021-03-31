/*	2020-12-20	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;

/*
 * using vector<set> for each vertex
 * !!Trick: merge size small to large
 * if ((int)distinct[u].size() < (int)distinct[v].size()) swap(distinct[u],distinct[v]);
*/
vector<int> color;
vector<set<int>> distinct;
vector<vector<int>> g;
vector<int> ans;
int n;

void dfs(int u,int p){
	distinct[u].insert(color[u]);
	for (const int &v: g[u]){
		if (v == p) continue;
		dfs(v,u);
		if ((int)distinct[u].size() < (int)distinct[v].size()) swap(distinct[u],distinct[v]);
		//for (const int &x: distinct[v]) distinct[u].insert(x);
	}
	
	for (const int &v: g[u]){
		if (v == p) continue;
		for (const int &x: distinct[v]) distinct[u].insert(x);
	}
	
	ans[u] = (int)distinct[u].size();
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	g.resize(n + 1);
	distinct.resize(n + 1);
	color.resize(n + 1);
	ans.resize(n + 1);
	for (int i = 1; i <= n; i++) cin >> color[i];
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	return 0;
}