/*	2020-12-16	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int INF = (int)(1e9)+10;
const ll MOD = (ll)(1e9) + 7;
const int Maxn = 2*int(1e5) + 5;
vector<int> a; 
vector<ll> fac(Maxn),inv(Maxn);

ll fast_pow(ll x,int y){
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
	for (int i = 1; i < Maxn; i++) fac[i] = (fac[i - 1]*(ll)i) % MOD;
	inv[Maxn - 1] = fast_pow(fac[Maxn - 1],MOD - 2);
	for (int i = Maxn - 2; i >= 0; i--) inv[i] = (inv[i + 1]*(ll)(i + 1)) % MOD;
}

ll C(int r,int n){
	if (r > n) return 0;
	ll tmp = fac[n];
	tmp = (tmp*inv[r]) % MOD;
	tmp = (tmp*inv[n - r]) % MOD;
	return tmp;
}

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	a.assign(n,0);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(all(a));
	
	ll ans = 0;
	// fix a[i] => choose m - 1 position in range [i + 1 -> j]
	for (int i = 0, j = 0; i < n; i++){
		while (j < n && a[j] - a[i] <= k) j++;
		ans = (ans + C(m - 1,j - i - 1)) % MOD;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	init();
	while (t--) solve();
	return 0;
}