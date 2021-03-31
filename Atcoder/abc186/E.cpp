/*	2020-12-25	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
ll N, S, K;

ll fast_pow(ll x,int y,ll Mod){
	ll ans = 1;
	while (y){
		if (y & 1) ans = (ans*x) % Mod;
		x = (x*x) % Mod;
		y >>= 1;
	}
	return ans;
}

int phi(int x){
	int res = x;
	for (int i = 2; i*i <= x; i++){
		if (x % i == 0){
			res -= res/i;
			while (x % i == 0) x /= i;
		}
	}
	if (x > 1) res -= res/x;
	return res;
}

void solve(){
	cin >> N >> S >> K;
	ll g = __gcd(N,__gcd(S,K));
	ll N1 = N/g;
	ll S1 = S/g;
	ll K1 = K/g;
	if (__gcd(K1,N1) > 1){
		cout << -1 << '\n';
		return;
	}

	// solve S1 + K1x = 0 (mod N1) , gcd(K1,N1) = 1
	ll x = (fast_pow(K1,phi(N1) - 1,N1)*((N1 - S1 + N1) % N1)) % N1;
	cout << x << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}