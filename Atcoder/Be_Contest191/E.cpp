/*	2021-02-18	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
vector<vector<ii>> g;
vector<vector<int>> dis;
vector<int> loop;
int n, m;

void dijsktra(int s){
	dis[s][s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	
	pq.push({0,s});
	while (!pq.empty()){
		int u = pq.top().second;
		int du = pq.top().first;
		pq.pop();
		if (du != dis[s][u]) continue;
		for (auto [w,v]: g[u])
			if (dis[s][v] > du + w){
				dis[s][v] = du + w;
				pq.push({du + w,v});
			}
	}
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	g.resize(n + 1);
	loop.assign(n + 1,INF);
	
	for (int i = 0; i < m; i++){
		int u, v, c;
		cin >> u >> v >> c;
		if (u == v) loop[u] = min(loop[u],c);
		else g[u].push_back({c,v});
		
	}
	
	dis.assign(n + 1,vector<int> (n + 1,INF));
	for (int i = 1; i <= n; i++) dijsktra(i);
	
	vector<int> ans(n + 1,INF);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++)
			if (i != j) ans[i] = min(ans[i],dis[i][j] + dis[j][i]);
		ans[i] = min(ans[i],loop[i]);
		if (ans[i] == INF) ans[i] = -1;
	}
	
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
	return 0;
}