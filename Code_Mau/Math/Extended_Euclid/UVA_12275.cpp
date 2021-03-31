#include <bits/stdc++.h>
using namespace std;
typedef long long ll;;
ll A, B, C, P;
int T;

//Extended_Eclid

ll gcd(ll a,ll b,ll &x,ll &y){
	if (a == 0){
		x = 0; y = 1;
		return b; 
	}
	ll x1, y1, d;
	d = gcd(b % a, a, x1,y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return d;
}

//Find_any_solution
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
void shift_solution(ll &x,ll &y,ll a,ll b, ll cnt){
	x += b*cnt;
	y -= a*cnt;
}

// find_all_solution
ll find_all_solution(ll a,ll b,ll c,ll minx, ll maxx, ll miny,ll maxy){
	ll x, y, g;
	if (!find_any_solution(a,b,c,x,y,g)) return 0;

	a /= g; b /= g;

	ll sign_a = (a > 0) ? 1: -1;
	ll sign_b = (b > 0) ? 1: -1;

	// minx <= x + kb <= maxx
	shift_solution(x,y,a,b,(minx - x)/b);
	if (x < minx) shift_solution(x,y,a,b,sign_b);
	if (x > maxx) return 0;
	ll lx1 = x;

	shift_solution(x,y,a,b,(maxx - x)/b);
	if (x > maxx) shift_solution(x,y,a,b,-sign_b);
	//if (x < minx) return 0;
	ll rx1 = x;

	// miny <= y - ka <= maxy
	shift_solution(x,y,a,b,-(miny - y)/a);
	if (y < miny) shift_solution(x,y,a,b,-sign_a);
	if (y > maxy) return 0;
	ll lx2 = x;

	shift_solution(x,y,a,b, -(maxy - y)/a);
	if (y > maxy) shift_solution(x,y,a,b,sign_a);
	ll rx2 = x;

	if (lx2 > rx2) swap(lx2,rx2);
	ll lx = max(lx1,lx2), rx = min(rx1,rx2);
	if (lx > rx) return 0;
	return (rx - lx)/abs(b) + 1;

}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	for (int i = 1; i <= T; i++){
		cin >> A >> B >> C >> P;
		ll g = __gcd(A,__gcd(B,C));
		if (P % g){
			cout << "Case " << i << ": " << 0 << '\n';
			continue;
		}

		A /= g; B /= g; C /= g; P /= g;

		ll ans = 0;
		ll cnt = 0;
		while (P - cnt*C >= 0){
			ll _P = P - cnt*C;
			ans += find_all_solution(A,B,_P,0,_P,0,_P);
			cnt++;
		}
		cout << "Case " << i << ": " << ans << '\n';
	}
	return 0;
}