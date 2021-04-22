/*	2021-04-18	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
//const int INF = (int)(1e9) + 10;
const ll INF = (ll)(1e18);
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<ll> s(n);
	for (ll &x: s) cin >> x;
	
	sort(all(s));
	vector<vector<ll>> dp(n,vector<ll> (n,INF));
	for (int i = 0; i < n; i++) dp[i][i] = 0;
	
	for (int L = n - 1; L >= 0; L--)
		for (int R = L + 1; R < n; R++)
			dp[L][R] = s[R] - s[L] + min(dp[L + 1][R],dp[L][R - 1]);
	cout << dp[0][n - 1];
	return 0;
}