/*	2021-07-01	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
vector<vector<int>> g;
vector<double> E;
int n;



void dfs(int u,int par){
	
	bool is_leaf = true;
	int num_branch = 0;
	for (int v: g[u])
		if (v != par) {
			dfs(v,u);
			num_branch++;
			E[u] += E[v];
			is_leaf = false;
		}
		
	if (!is_leaf){
		E[u]/=num_branch;
		E[u] = E[u] + 1;
	}
	else E[u] = 0;
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	
	g.resize(n);
	E.resize(n);
	
	for (int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
		
	}
	dfs(0,-1);
	cout << fixed << setprecision(7) << E[0];
	return 0;
}
