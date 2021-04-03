/*	2021-04-03	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const int Maxn = 5*int(1e4);
// using topo-sort bfs + biset mark 

vector<vector<int>> g;
vector<bitset<Maxn>> f;
vector<bool> vis;
int n, m;


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	g.assign(n,vector<int>());
	vector<int> in(n);
	for (int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[v].push_back(u);
		in[u]++;
	}
	
	// biset 
	f.resize(n);
	vis.assign(n,false);
	
	// Topo and Calculation
	queue<int> q;
	for (int i = 0; i < n; i++){
		if (in[i] == 0) q.push(i);
		f[i].set(i); 
	}
	
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (int v: g[u]){
			f[v] |= f[u];
			if ((--in[v]) == 0) q.push(v);
		}
	}
	for (int i = 0; i < n; i++) cout << f[i].count() << ' ';
	return 0;
}