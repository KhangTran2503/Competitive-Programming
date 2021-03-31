#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int INF = int(1e9);

vector<vector<pair<int,char>>> g;
vector<int> d;
int n, m;

void bfs(int s){
	d.assign(n,INF);
	d[s] = 0;
	queue<int> q;
	q.push(s);
	
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (pair<int,char> uv: g[u]){
			int v = uv.first;
			if (d[u] + 1 < d[v]){
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	g.resize(n);
	
	for (int i = 0; i < m; i++){
		int u,v;
		char c;
		cin >> u >> v >> c;
		u--, v--;
		g[u].eb(v,c);
		g[v].eb(u,c);
	}

	bfs(n - 1);

	vector<int> curlayer;

	vector<int> par(n);
	par.assign(n,-1);

	vector<char> ans;

	curlayer.eb(0);
	while (1){
		char minletter = 'z';
		
		bool isend = false;

		for (int u: curlayer){
			isend |= (u == n - 1);
			for (pair<int,char> uv: g[u]){
				int v = uv.first;
				char eletter= uv.second;
				if (d[v] == d[u] - 1){
					minletter = min(minletter,eletter);
				}
			}
		}

		if (isend) break;

		ans.eb(minletter);

		vector<int> nextlayer;
		for (int u: curlayer){
			for (pair<int,char> uv: g[u]){
				int v = uv.first;
				int eletter = uv.second;
				if (d[u] - 1 == d[v] && minletter == eletter){
					if (par[v] == -1){
						par[v] = u;
						nextlayer.eb(v);
					}
				}
			}
		}
		curlayer = nextlayer;
	}

	vector<int> anspath;
	for (int u = n - 1; u != -1; u = par[u]){
		anspath.eb(u);
	}

	reverse(anspath.begin(),anspath.end());
	cout << ans.size() << '\n';
	for (int u: anspath) cout << u + 1 << ' ';
	cout << '\n';
	for (char x: ans) cout << x;

	return 0;
}
