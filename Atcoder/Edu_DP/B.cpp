#include <bits/stdc++.h>
#define oo int(1e9)
using namespace std;
int n, k;

int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	cin >> n >> k;
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	vector<int> dp(n);
	for (int i = 1; i < n; i++) dp[i] = oo;
	for (int i = 0; i < n; i++)
	    if (dp[i] < oo){
	       for (int j = 1; j <= k && i + j < n; j++)
	        dp[i + j]  = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
	    }
	cout << dp[n - 1];
	return 0;
}
