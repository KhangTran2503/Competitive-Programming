#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<ll> a(n);
	for (ll &x: a) cin >> x;
	
	ll maxpre = 0;
	ll move = 0;
	ll premove = 0;
	ll ans = 0;
	for (ll x: a){
		move += x;
		maxpre = max(maxpre,move);
		ans = max(ans,premove + maxpre);
		premove += move;
	}
	cout << ans;
	return 0;
}
