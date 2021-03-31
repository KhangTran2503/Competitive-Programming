/*	2021-01-31	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const int Maxn = int(1e6) + 1;
const ll Mod = (ll)(1e9) + 7;

// f[i] is number ways use two ties with width 1
// g[i] is number ways use a tile with width 2

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	vector<ll> f(Maxn), g(Maxn);
	f[1] = 1;
	g[1] = 1;
	for (int i = 2; i < Maxn; i++){
		f[i] = (f[i - 1] + f[i - 1] + g[i - 1]) % Mod;
		g[i]  = (4*g[i - 1] + f[i - 1]) % Mod;
	}
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		ll ans = (f[n] + g[n]) % Mod;
		cout << ans << '\n';
	}
	return 0;
}