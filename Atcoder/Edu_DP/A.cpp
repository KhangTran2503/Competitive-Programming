#include <bits/stdc++.h>
#define oo int(1e9)
using namespace std;
int n;

int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++) cin >> h[i];
	vector<int> dp(n);
	for (int i = 1; i < n; i++) dp[i] = oo;
	for (int i = 0; i < n; i++)
	    if (dp[i] < oo){
	        if (i + 1 < n) dp[i + 1] = min(dp[i + 1],dp[i] + abs(h[i] - h[i + 1]));
	        if (i + 2 < n) dp[i + 2] = min(dp[i + 2],dp[i] + abs(h[i] - h[i + 2]));
	    }
	cout << dp[n - 1];
	return 0;
}
