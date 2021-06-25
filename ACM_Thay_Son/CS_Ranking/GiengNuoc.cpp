/*	2021-06-20	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int dx[] = {-1,0,0,1},
	dy[] = {0,-1,1,0};
int n, m;

bool is_feasible(int x,int y){
	return (x >= 0 && x < n && y >= 0 && y < m);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	vector<vector<int>> a(n,vector<int> (m + 1));
	vector<vector<int>> d(n,vector<int> (m + 1));
	queue<ii> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
			if (a[i][j] == 0) {
				q.push({i,j});
				d[i][j] = 1;
			}
		}
		
	while (!q.empty()){
		ii u = q.front();
		q.pop();
		for (int i = 0; i < 4; i++){
			int vx = u.first + dx[i];
			int vy = u.second + dy[i];
			if (is_feasible(vx,vy) && (d[vx][vy] == 0) && (a[vx][vy] == 1)){
				d[vx][vy] = d[u.first][u.second] + 1;
				q.push({vx,vy});
 			}
		}
	}	
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) cout << d[i][j] - 1 << ' ';
		cout << '\n';
	}
	return 0;
}
