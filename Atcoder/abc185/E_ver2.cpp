/*	2020-12-14	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9)+100;
int a[1005], b[1005];
int dp[1005][1005];
int n, m;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int j = 1; j <= m; j++) cin >> b[j];
	for (int i = 1; i <= m; i++) dp[0][i] = i;
	for (int i = 1; i <= n; i++) dp[i][0] = i;
	dp[0][0] = 0;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			dp[i][j] = min({dp[i -1][j] + 1,dp[i][j - 1] + 1,dp[i - 1][j - 1] + (int)(a[i] != b[j])});
		}
	cout << dp[n][m];
	return 0;
}