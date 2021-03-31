#include <bits/stdc++.h>
#define oo int(1e9)
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e18);
string s, t;
vector<vector<int>> dp;
int n, m;
// LCS
int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	cin >> s;
	cin >> t;
	n = s.size();
	m = t.size();
	dp.resize(n + 1,vector<int> (m + 1));
	for (int i = 1; i <= n; i++)
	    for (int j = 1; j <= m; j++)
	        if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i -1][j - 1] + 1;
	        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	vector<char> ans;
	while (n > 0 && m > 0){
	    if (s[n - 1] == t[m - 1]){
	        ans.push_back(s[n - 1]);
	        n--; m--;
	    }
	    else if (dp[n][m] == dp[n - 1][m]) n--;
	       else  m--;
	}
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
	return 0;
}
