/*	2021-07-05	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const ll INF = (ll)(1e15) + 10;
// Floyd–Warshall algorithm

ll dp[405][405][405];

void init(){
	for (int i = 0; i <= 400; i++)
		for (int j = 0; j <= 400; j++)
			for (int k = 0; k <= 400; k++) dp[i][j][k] = INF;
}

int n, m;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	init();
	cin >> n >> m;
	for (int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		dp[0][a][b] = c;
		//dp[0][b][a] = c;
	}
	
	for (int i = 1; i <= n; i++) dp[0][i][i] = 0;
	
	ll ans = 0;
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[k][i][j] = min(dp[k - 1][i][j],dp[k - 1][i][k] + dp[k - 1][k][j]);		
	}
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dp[k][i][j] < INF) ans += dp[k][i][j];
	cout << ans;
	return 0;
}
