/*	2021-06-30	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int L, R;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> L >> R;
	
	// dp[i] is number pair (x,y) such that i = gcd(x,y)
	// x != y
	vector<ll> dp(R + 1);
	for (int i = R; i >= 1; i--){
		ll num = (R/i) - ((L - 1)/i);
		dp[i] = num*num;
		for (int j = i + i; j  <= R; j+=i) dp[i] -= dp[j];
	}
	
	// calculate (x,y) such that x |y in range [L,R]
	// O(n)
	
	ll t1 = 0;
	for (int i = max(2,L); i <= R; i++){
		ll cnt = (R/i) - ((L - 1)/i);
		// don't compute (x,x)
		cnt = 2*cnt - 1;
		t1 += cnt;
	}
	
	ll all = (ll)(R - L + 1)*(ll)(R - L + 1);
	ll ans = all - dp[1] - t1;
	cout << ans;
	
	
	return 0;
}
