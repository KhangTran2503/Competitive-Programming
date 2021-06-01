/*	2021-05-31	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const ll MOD = (ll)(1e9) + 7;
const int MaxN = int(1e5) + 10;
vector<ll> fac(MaxN), invfac(MaxN);
int N, K;

ll binpow(ll x,ll y){
	ll ans = 1;
	while (y){
		if (y & 1) ans = (ans*x) % MOD;
		x = (x*x) % MOD;
		y >>= 1;
	}
	return ans;
}

void init(){
	fac[0] = 1;
	for (int i = 1; i < MaxN; i++) fac[i] = (fac[i - 1]*(ll)i) % MOD;
	invfac[MaxN - 1] = binpow(fac[MaxN - 1],MOD - 2);
	for (int i = MaxN - 2; i >= 0; i--) invfac[i] = (invfac[i + 1]*(ll)(i + 1)) % MOD;
}

ll C(int k,int n){
	if (k > n || k < 0) return 0;
	ll res = fac[n];
	res = (res*invfac[k]) % MOD;
	res = (res*invfac[n - k]) % MOD;
	return res;
}

void solve(){
	// day bat bong den do dai p
	cin >> N >> K;
	ll ans = 1;

	for (ll p = 1; N - (K - 1)*(p - 1) >= p; p++){
		int tmp = C(p,N - (K - 1)*(p - 1));
		tmp = (tmp*fac[p]) % MOD;
		tmp = (tmp*fac[N - p]) % MOD;
		tmp = (tmp*invfac[N]) % MOD;
		ans = (ans + tmp) % MOD;
	}
	cout << ans << '\n';
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	
	init();
	cin >> T; 
	while (T--) solve();
	return 0;
}