#include <bits/stdc++.h>
using namespace std;
string s, t;


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> t;
	int m = s.size();
	int n = t.size();

	vector<vector<int>> dp(m + 1,vector<int> (n + 1,0));

	for (int i = 1; i <= m; i++) dp[i][0] = i;
	for (int i = 1; i <= n; i++) dp[0][i] = i;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j];
			else dp[i + 1][j + 1] = min(dp[i + 1][j],min(dp[i][j],dp[i][j + 1])) + 1;
	cout << dp[m][n];
	return 0;
}
