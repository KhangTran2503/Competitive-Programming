#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int INF = int(1e9);
int R, C;
vector<vector<char>> Map;
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

bool check(int u,int v){
	return (u >= 0) && (u < R) && (v >= 0) && (v < C) && (Map[u][v] != '@');
}


int bfs_01(){
	vector<vector<int>> dis(R,vector<int> (C,INF));
	deque<ii> dq;
	for (int i = 0; i < C; i++)
		if (check(0,i)){
			if (Map[0][i] == '.'){
				dis[0][i] = 1;
				dq.push_back({0,i});
			}
			else{
				dis[0][i] = 0;
				dq.push_front({0,i});
			}
		}
		
	for (int i = 0; i < R; i++)
		if (check(i,C - 1)){
			if (Map[i][C - 1] == '.'){
				dis[i][C - 1] = 1;
				dq.push_back({i,C - 1});
			}
			else {
				dis[i][C - 1] = 0;
				dq.push_front({i,C - 1});
			}
		}
	
	while (!dq.empty()){
		int ux = dq.front().first;
		int uy = dq.front().second;
		dq.pop_front();
		for (int k = 0; k < 8; k++){
			int vx = ux + dx[k];
			int vy = uy + dy[k];
			if (check(vx,vy)){
				if (Map[vx][vy] == '.'){
					if (dis[ux][uy] + 1 < dis[vx][vy]){
						dis[vx][vy] = dis[ux][uy] + 1;
						dq.push_back({vx,vy});
					}
				}
				else {
					if (dis[ux][uy] < dis[vx][vy]){
						dis[vx][vy] = dis[ux][uy];
						dq.push_front({vx,vy});
					}
				}
			}
		}
	}
	
	int ans = INF;
	for (int i = 0; i < C; i++) ans = min(ans,dis[R - 1][i]);
	for (int i = 0; i < R; i++) ans = min(ans,dis[i][0]);
	
	if (ans == INF) return -1;
	else return ans;
}


bool Solve(){
	cin >> R >> C;
	if (R == 0 && C == 0) return false;
	Map.assign(R,vector<char> (C,'.'));
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; ++j) cin >> Map[i][j];
	
	cout << bfs_01() << '\n';
	
	return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (Solve());
	return 0;
}
