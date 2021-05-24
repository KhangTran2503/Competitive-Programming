/*	2021-05-06	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const ll Mod = (ll)(1e9) + 7;
const int Maxn = int(2e5) + 10;
vector<ll> fac(Maxn);
vector<ll> inv_fac(Maxn);

ll binpow(ll x,int y){
	ll ans = 1;
	while (y){
		if (y & 1) ans = (ans*x) % Mod;
		x = (x*x) % Mod;
		y >>= 1;
	}
	return ans;
}

void init(){
	fac[0] = 1;
	for (int i = 1; i < Maxn; i++) fac[i] = (fac[i - 1]*i) % Mod;
	inv_fac[Maxn - 1] = binpow(fac[Maxn - 1],Mod - 2);
	for (int i = Maxn - 2; i >= 0; i--) inv_fac[i] = (inv_fac[i + 1]*(ll)(i + 1)) % Mod;
}


ll C(int r,int n){
	ll ans = fac[n];
	ans = (ans*inv_fac[r]) % Mod;
	ans = (ans*inv_fac[n - r]) % Mod;
	return ans;
}

void solve(){
	int n;
	cin >> n;
	cout << C(n,n - 1 + n) << '\n';
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	init();
	while (T--) solve();
	return 0;
}