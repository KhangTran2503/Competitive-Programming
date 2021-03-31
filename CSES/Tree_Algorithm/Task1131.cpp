/*	2020-12-18	*/
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
vector<int> dis;
int n;

pair<int,int> bfs(int u){
	dis.assign(n,INF);
	queue<int> q;
	q.push(u);
	dis[u] = 0;
	while (!q.empty()){
		int uu = q.front();
		q.pop();
		for (int v: g[uu])
			if (dis[v] == INF){
				dis[v] = dis[uu] + 1;
				q.push(v);
			}
	}
	int so_far = u;
	for (int i = 0; i < n; i++)
		if ((dis[i] != INF) && (dis[i] > dis[so_far]) ) so_far = i;
	return {so_far,dis[so_far]};	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	ii ans = bfs(0);
	//cout << ans.second << '\n';
	ans = bfs(ans.first);
	cout << ans.second; 
	return 0;
}