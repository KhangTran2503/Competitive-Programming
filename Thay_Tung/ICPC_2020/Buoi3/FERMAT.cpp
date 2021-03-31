#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<ll,ll,ll,ll> tup;
ll lf, rf;
ll max_m;

ll get_max(ll x){
	ll m = 3;
	while (m*m*m*(m - 2) < x) m++;
	return m;
}

tup get_first(ll x,ll m){
	ll a = x/(m*m*(m - 2));
	x %= m*m*(m - 2);
	ll b = x/m*(m - 2);
	x %= m*(m - 2);
	ll c = x/(m - 2);
	ll n = x % (m - 2);
	return make_tuple(a + 1,b + 1,c + 1,n + 3);
}

void next_config(tup &v,ll &m){
	ll a,b,c,n;
	tie(a,b,c,n) = v;
	if (n < m){
		n++;
		v = make_tuple(a,b,c,n);
		return;
	}
	
	if (c < m){
		c++;
		
	}
}


void print_ans(tup v){
	ll a, b, c, n;
	tie(a,b,c,n) = v;
	if (max(a,b) >= c){
		z
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> lf >> rf;
	
	max_m = get_max(lf);
	tup config = get_first(lf - 1,max_m);
	int a,b,c,n;
	tie(a,b,c,n) = config;
	cout << a << ' ' << b << ' ' << c << ' ' << n;
	
	return 0;
}
