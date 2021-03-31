#include <bits/stdc++.h>
#define oo int(1e9)
using namespace std;
typedef long long ll;
int n, W;

// Dp knacksack bth
int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	cin >> n >> W;
	vector<int> w(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
	vector<ll> dp(W + 1);
	for (int i = 0; i < n; i++)
	    for (int j = W; j >= w[i]; j--)
	        dp[j] = max(dp[j], dp[j - w[i]] + (ll)v[i]);
	 cout << dp[W];

	return 0;
}
