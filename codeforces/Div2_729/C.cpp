/*	2021-07-03	 */
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



void solve(){
	ll n;
	cin >> n;
	
	ll ans = 0;
	ll prelcm = 1;
	ll curlcm;
	for (int x = 2; x <= 50; x++){
		curlcm = (prelcm/__gcd((ll)x,prelcm))*(ll)x;
		ll num = (n/prelcm) % Mod - (n/curlcm) % Mod;
		num = (num + Mod) % Mod;
		ans = (ans + num*(ll)x) % Mod;
		prelcm = curlcm;
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}
