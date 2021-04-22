/*	2021-04-06	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const ll MOD = 998244353;
const ll inv2 = (MOD + 1)/2LL;

int n;
vector<ll> a;

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		//a[i] %= MOD;
	}
	
	sort(a.begin() + 1,a.end());
	ll pinv2 = inv2;
	vector<ll> pre(n + 1);
	for (int i = 1; i <= n; i++){
		pinv2 = (pinv2*inv2) % MOD;
		pre[i] = (a[i]*pinv2) % MOD;
	}
	
	vector<ll> pw2(n + 1);
	pw2[0] = 1;
	for (int i = 1; i <= n; i++) pw2[i] = (pw2[i - 1]*2LL) % MOD;
	
	ll ans = 0;
	ll sumsuffix = 0;
	for (int i = n; i >= 2; i--){
		sumsuffix = (sumsuffix + (a[i]*pw2[i]) % MOD) % MOD;
		ans = (ans + (pre[i - 1]*sumsuffix) % MOD) % MOD;
	}
	for (int i = 1; i <= n; i++)
		ans = (ans + (a[i]*a[i]) % MOD) % MOD;
	cout << ans;
	return 0;
}