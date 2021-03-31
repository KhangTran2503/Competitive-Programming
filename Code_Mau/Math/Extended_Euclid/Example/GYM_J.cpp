// NO AC
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e10);
ll n, m, u, v;

// Extend_Euclid
ll gcd(ll a,ll b,ll &x, ll &y){
	if (a == 0){
		x = 0, y = 1;
		return b;
	}
	ll x1, y1, d;
	d = gcd(b % a, a, x1, y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return d;
}

// find_any_solution
bool find_any_solution(ll a,ll b,ll c,ll &x0,ll &y0,ll &g){
	g = gcd(abs(a),abs(b),x0,y0);
	if (c % g) return false;

	x0 *= (c/g);
	y0 *= (c/g);

	if (a < 0) x0 = -x0;
	if (b < 0) y0 = -y0;
	return true;
}

// shift_solution
void shift_solution(ll &x, ll &y,ll a,ll b,ll cnt){
	x += cnt*b;
	y -= cnt*a;
}


ll find_solution(ll a,ll b,ll c,ll minx,ll miny){
	if (a == 0 && b == 0 ){
		if (c == 0) return n;
		else return -1;
	}
	ll x, y, g;
	if (!find_any_solution(a,b,c,x,y,g)) return -1;
	//cout << x << ' ' << y << '\n';
	if (a == 0){
		ll k = c/b;
		if (k >= 0) return n;
		else return -1;
	}
	if (b == 0){
		ll k = c/a;
		if (k >= 0) return u;
		else return -1;
	}

	a /= g;
	b /= g;
	//cout << a << ' ' << b << '\n';
	ll lk1 = -INF, rk1 = INF;
	ll lk2 = -INF, rk2 = INF;
	if (b > 0)
		 lk1 = (-x/b) + (abs(x) % abs(b) != 0);
	else rk1 = (-x/b) - (abs(x) % abs(b) != 0);
	
	if (a > 0)
		 rk2 = (y/a) - (abs(y) % abs(a) != 0);
	else lk2 = (y/a) + (abs(y) % abs(a) != 0);
	//cout << lk1 << ' ' << rk1 << '\n';
	//cout << lk2 << ' ' << rk2 << '\n';
	ll lk = max(lk1,lk2);
	ll rk = min(rk1,rk2);
	if (lk > rk) return -1;
	if (b < 0) x = x + b*rk;
	else x = x + b*lk;
	return n + x*m;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1){
		cin >> n >> m >> u >> v;
		if (n == 0 && m == 0 && u == 0 &&  v == 0) break;
		ll ans = find_solution(m,-v,u - n,0,0);
		if (ans == -1) cout << "Impossible\n";
		else cout << ans << '\n';
	}
	return 0;
}