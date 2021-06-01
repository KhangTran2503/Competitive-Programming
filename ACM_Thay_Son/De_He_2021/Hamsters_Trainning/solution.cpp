/*	2021-05-25	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
ll n, p;
int Q;
vector<ll> fac, inv_fac;

ll fast_pow(ll x,ll y){
	ll ans = 1;
	x %= p;
	while (y){
		if (y & 1) ans = (ans*x) % p;
		x = (x*x) % p;
		y >>= 1;
	}
	return ans;
}


void init(){
	fac.resize(p);
	inv_fac.resize(p);
	fac[0] = 1;
	for (int i = 1; i < p; i++)
		fac[i] = (fac[i - 1]*(ll)i) % p;
	
	inv_fac[p - 1] = fast_pow(fac[p - 1],p - 2);
	for (int i = p - 2; i >= 0; i--)
		inv_fac[i] = (inv_fac[i + 1]*(ll)(i + 1)) % p;
}

ll C(int k,int n){
	if (n < k) return 0;
	ll res = (fac[n]*inv_fac[k]) % p;
	res = (res*inv_fac[n - k]) % p;
	return res;
}

ll calc(ll x){
	ll m = 2*x  - 1, n = x;
	ll ans = 1;
	while (n > 0 || m > 0){
		ll u = n % p, v = m % p;
		ans = (ans*C(u,v)) % p;
		n /= p;
		m /= p;
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> Q >> p;
	init();
	
	while (Q--){
		cin >> n;
		cout << calc(n) << '\n';
	}
	return 0;
}