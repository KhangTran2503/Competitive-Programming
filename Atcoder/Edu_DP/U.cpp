/*	2020-12-10	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const ll INF = (ll)(1e10);
int n;
vector<vector<int>> a;
vector<ll> cost;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	a.resize(n,vector<int> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> a[i][j];
	
	// precalc for each subset n^2*2^n
	cost.resize(1 << n);
	for (int msk = 0; msk < (1 << n); msk++){
		for (int u = 0; u < n; u++)
			if ((msk >> u) & 1){
				for (int v = u; v < n; v++)
					if ((msk >> v) & 1) cost[msk] += (ll)a[u][v];
			}
	}
	
	// DP over on subset 3^n
	vector<ll> dp(1 << n,-INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++) dp[1 << i] = 0;
	for (int msk = 0; msk < (1 << n); msk++){
		dp[msk] = max(dp[msk],dp[0] + cost[msk]);
		for (int s = msk; s > 0; s = (s - 1)&msk){
			dp[msk] = max(dp[msk],dp[s] + cost[msk^s]);
		}
	}
	cout << dp[(1 << n) - 1];
	return 0;
}