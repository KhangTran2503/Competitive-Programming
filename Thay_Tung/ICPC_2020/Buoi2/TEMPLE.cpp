#include <bits/stdc++.h>
#define all(s) (s).begin(), (s).end()
using namespace std;
typedef long long ll;
const int INF = (int)(1e9);
typedef pair<int,int> ii;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
vector<vector<char>> Map;
vector<vector<int>> dis;
int n, m;
ii S, F;
int k;

bool check(int u,int v){
	return (u >= 0 && u < n && v >= 0 && v < m && Map[u][v] != '#');
}

int bfs(ii s,ii t){
	if (!check(s.first,s.second)) return INF;
	if (!check(t.first,t.second)) return INF;
	for (int i = 0; i < n; i++) fill(all(dis[i]),INF);
	queue<ii> q;
	q.push(s);
	dis[s.first][s.second] = 0;
	while (!q.empty()){
		ii u = q.front();
		q.pop();
		for (int h = 0; h < 4; h++){
			int vx = u.first + dx[h];
			int vy = u.second + dy[h];
			if (check(vx,vy) && dis[vx][vy] == INF ){
				dis[vx][vy] = dis[u.first][u.second] + 1;
				q.push(make_pair(vx,vy));
			}
		}
	}
	return dis[t.first][t.second];
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	
	Map.resize(n,vector<char>(m));
	dis.assign(n,vector<int> (m,INF));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> Map[i][j];
			if (Map[i][j] == 'S') S = {i,j};
			if (Map[i][j] == 'F') F = {i,j};
		}
	
	vector<ii> rocks(k);
	for (ii &r: rocks) {
		cin >> r.first >> r.second;
		r.first--;
		r.second--;
	}
	
	int ans = INF;
	if (k == 0) ans = bfs(S,F);
	else {
		vector<vector<int>> dp(k,vector<int> (4,INF));
		for (int h =0; h < 4; h++){
			int rx0 = rocks[0].first + dx[h];
			int ry0 = rocks[0].second + dy[h];
			if (check(rx0,ry0)) dp[0][h] = bfs(S,{rx0,ry0});
			//else dp[0][h] = INF;
		}
		
		for (int i = 1; i < k; i++)
			for (int k1 = 0; k1 < 4; k1++){
				int rx1 = rocks[i - 1].first + dx[k1]; 
				int ry1 = rocks[i - 1].second + dy[k1];
				for (int k2 = 0; k2 < 4; k2++){
					int rx2 = rocks[i].first + dx[k2];
					int ry2 = rocks[i].second + dy[k2];
					dp[i][k2] = min(dp[i][k2],dp[i - 1][k1] + bfs({rx1,ry1},{rx2,ry2}));
				}
			}
		
		for (int h =0; h < 4; h++){
			int rxk = rocks[k - 1].first + dx[h];
			int ryk = rocks[k - 1].second + dy[h];
			if (check(rxk,ryk)) ans = min(ans,dp[k - 1][h] + bfs(F,{rxk,ryk}));
		}
	}
	
	if (ans >= INF) cout << -1;
	else cout << ans; 
	return 0;
}
