#include <bits/stdc++.h>
#define oo int(1e9)
using namespace std;
int n, k;

int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	cin >> n;
	vector<vector<int>> vac,dp;
	vac.resize(n, vector<int> (3));
	dp.resize(n, vector<int> (3));
	for (int i = 0; i < n; i++) cin >> vac[i][0] >> vac[i][1] >> vac[i][2];
	dp[0] = vac[0];
	for (int i = 1; i < n; i++)
	    for (int j = 0; j < 3; j++)
	        for (int k = 0; k < 3; k++)
	            if (k != j) dp[i][j] = max(dp[i][j] , dp[i - 1][k] + vac[i][j]);

	int ans = 0;
	for (int j = 0; j < 3; j++) ans = max(ans, dp[n - 1][j]);
	cout << ans;
	return 0;
}
