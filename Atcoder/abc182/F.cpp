/* find b = [b1, b2, ... , bn] such that a = [a1,..,an] , a^T*b = X
 * 
 *  => DP Knapsack
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll X;
vector<map<ll,ll>> memo;
vector<ll> c;
vector<ll> a;

ll dp(int pos,ll value){
	if (pos == N) return 1LL;
	if (memo[pos].find(value) != memo[pos].end()) return memo[pos][value];
	
		
	ll ans = dp(pos + 1,(value/a[pos])*a[pos]);
	ll r = value % a[pos];
	if (r)
		ans += dp(pos + 1,(value/a[pos] + 1)*a[pos]);
	//else ans += dp(pos + 1,value/c[pos] - 1);
	return memo[pos][value] = ans;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> X;
	a.resize(N + 1);
	for (int i = 0; i < N; i++) cin >> a[i];
	a[N] = a[N - 1];
	
	//c.resize(N);
	//for (int i = 0; i < N; i++) c[i] = a[i + 1]/a[i];
	
	memo.resize(N);
	cout << dp(0,X);
	return 0;
}
