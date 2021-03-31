/*	2021-01-31	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int q;
ll k;

ll fastpow(int y){
	ll ans = 1;
	ll x = 10;
	while (y){
		if (y & 1) ans = (ans*x);
		x = x*x;
		y >>= 1;
	}
	return ans;
}

void solve(){
	cin >> k;
	ll pos = 1;
	ll num = 9;
	while (pos*num < k){
		k -= pos*num;
		pos++;
		num *= 10;
	}
	//cout << pos << ' ' << k << '\n';
	//ll last = fastpow(pos - 1) - 1;
	if (pos == 1) cout << k << '\n';
	else {
		ll block = (k - 1)/pos;
		ll remain = (k - 1) % pos;
		ll n = fastpow(pos - 1) + block;
		ll cur_pos = pos - remain;
		ll ans;
		while (cur_pos--){
			ans = n % 10;
			n /= 10;
		}
		cout << ans << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> q;
	while (q--) solve();
	return 0;
}