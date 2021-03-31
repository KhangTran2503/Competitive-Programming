#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9) + 7;
ll inv2 = (MOD + 1) >> 1;

int fastpow(ll x,int y){
	ll ans = 1;
	while (y){
		if (y & 1) ans = (ans*x) % MOD;
		x = (x*x) % MOD;
		y >>= 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--){
		ll n;
		cin >> n;
		ll ans = (n*(n + 1)) % MOD;
		ans = (ans *(n + 2)) % MOD;
		ans = (ans*(n + 3)) % MOD;
		ans = (ans*fastpow(24,MOD - 2)) % MOD;
		cout << ans << '\n';
	}
	return 0;
}