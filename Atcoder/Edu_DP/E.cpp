#include <bits/stdc++.h>
#define oo int(1e9)
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e18);
int n, W;

// DP nay vi W qua lon nen doi dk \
// goi dp[j] la tong cac value bang j va co tong cac weight be nha
// Tim j lon nhat s cho dp[j] <= W
int main() {
	cin.tie(0); ios::sync_with_stdio(0); cout.tie(0);
	cin >> n >> W;
	vector<int> w(n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> w[i] >> v[i];

	int sumvalue = 0;
	for (int x: v) sumvalue += x;

	vector<ll> dp(sumvalue + 1,INF);
	dp[0] = 0;
	for (int i = 0; i < n; i++)
	    for (int j = sumvalue; j >= v[i]; j--)
	        dp[j] = min(dp[j], dp[j - v[i]] + (ll)w[i]);

	for (int j = sumvalue; j > 0; j--)
	    if (dp[j] <= W){
	        cout << j;
	        break;
	    }

	return 0;
}
