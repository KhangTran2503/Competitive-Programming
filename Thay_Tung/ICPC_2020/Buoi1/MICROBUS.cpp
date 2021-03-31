/* dp[i][j] la xet 1->i xe va bo tri 1-> j chuyen
 * 
 * dp[i][j] = dp[i - 1][j - 1] + |ai - bj|
 *          = dp[i - 1][j] + q
 * 			= dp[i][j - 1] + p
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, p, q;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> p >> q;
	vector<int> a(n + 1);
	vector<int> b(m + 1);
	for (int i =1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	
	sort(a.begin() + 1,a.end());
	sort(b.begin() + 1,b.end());
	vector<vector<ll>> dp(n + 1,vector<ll> (m + 1,0));
	
	for (int i = 1; i <= m; i++) dp[0][i] = i*q;
	for (int i = 1; i <= n; i++) dp[i][0] = i*p;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) 
			dp[i][j] = min({dp[i - 1][j - 1] + abs(a[i] - b[j]),dp[i - 1][j] + p,dp[i][j - 1] + q});
	
	cout << dp[n][m];
	
	return 0;
}
