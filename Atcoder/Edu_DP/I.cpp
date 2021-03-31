#include <bits/stdc++.h>
#define oo int(1e9)
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
typedef double db;
const ll MOD = (ll)(1e9) + 7;
int n;
vector<db> p;
vector<vector<db>> dp;
// dp[i][j] la tong xac suat chon 1->i va co j cai head
// dp[i][j] = dp[i - 1][j - 1]*p[i] + dp[i - 1][j]*(1 - p[i])
// dp[0][0] = 1, dp[i][0] = dp[i - 1][0]*(1 - p[i])

int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    p.resize(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    dp.resize(n + 1,vector<db> (n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) dp[i][0] = dp[i - 1][0]*(1 - p[i - 1]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i][j] = dp[i - 1][j - 1]*p[i - 1] + dp[i - 1][j]*(1 - p[i - 1]);

    db ans = 0;
    for (int i = n; i > n/2; i--) ans += dp[n][i];
    cout << fixed << setprecision(10) << ans;
	return 0;
}
