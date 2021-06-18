/*	2021-06-18	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const ll Mod = (ll)(998244353);
const int  Maxn = 5*int(1e5) + 5;
vector<ll> fac(Maxn);
vector<ll> invfac(Maxn);

ll binpow(ll x,ll y){
	ll ans = 1;
	while (y ){
		if (y & 1) ans = (ans*(ll)x) % Mod;
		x = (x * x) % Mod;
		y >>= 1;
	}
	return ans;
}

void init(){
	fac[0] = 1;
	for (int i = 1; i < Maxn; i++) fac[i] = (fac[i - 1]*i) % Mod;
	invfac[Maxn - 1] = binpow(fac[Maxn - 1],Mod - 2);
	for (int i = Maxn - 2; i >= 0; i--) invfac[i] = (invfac[i + 1]*(ll)(i + 1)) % Mod;
}

ll C(int k,int n){
	if (k > n) return 0;
	ll tmp = fac[n];
	tmp = (tmp*invfac[k]) % Mod;
	tmp = (tmp*invfac[n - k]) % Mod;
	return tmp;
}

// ai is multiple of a1
// proof by counter-evidence

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	
	init();
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		int cnt = (n/i);
		ans = (ans + C(k - 1,cnt - 1)) % Mod;
	}
	cout << ans;
	return 0;
}
