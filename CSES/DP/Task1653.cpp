/*	2021-06-01	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
// Dp bitmask + 
// From permutations to subsets

// pair<int,int> dp[mask].first is the minimum number of riders for a subset mask
//				 dp[mask].second is the minimum way of last rides
int n, x;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> x;
	vector<int> w(n);
	
	for (int &wi: w) cin >> wi;
	
	vector<pair<int,int>> dp(1 << n);
	
	dp[0] = {1,0};
	for (int mask = 1; mask < (1 << n); mask++){
		dp[mask] = {n,0};
		for (int i = 0; i < n; i++)
			if ((mask >> i) & 1){
				ii pre_state = dp[mask ^ (1 << i)];
				if (pre_state.second + w[i] <= x) pre_state.second += w[i];
				else {
					pre_state.first += 1;
					pre_state.second = w[i];
				}
				dp[mask] = min(dp[mask],pre_state);
			} 
	}
	
	cout << dp[(1 << n) - 1].first;
	return 0;
}