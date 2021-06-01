/*	2021-05-27	*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
const ll Mod = 998244353;
vector<vector<int>> d;
int n, m;

ll binpow(ll x,ll y){
	ll ans = 1;
	while (y){
		if (y & 1) ans = (ll)(ans*x) % Mod;
		x = (ll)(x*x) % Mod;
		y >>= 1;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	d.resize(n + 1,vector<int> (m + 1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) cin >> d[i][j];	
	
	ll fac_n = 1;
	for (int i = 1; i <= n; i++) fac_n = (ll)(fac_n*i) % Mod;
	ll invfac_n = binpow(fac_n,Mod - 2);

	vector<int> cnt(n + 2);
	
	ll ans = 0;
	for (int j = 1; j <= m; j++){
		fill(all(cnt),0);
		for (int i = 1; i <= n; i++)
			cnt[n + 2 - d[i][j]]++;
			
		
		//return 0;
		for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
		
		
		
		ll way = 1;
		for (int i = 1; i <= n; i++){
			way = (ll)(way*(ll)max(0,cnt[i] - i + 1)) % Mod;
			//cout << way << " \n"[i == n];
		}
		
		ll Pr0 = (ll)(way*invfac_n) % Mod;
		ans = (ans + 1 - Pr0 + Mod) % Mod;
	}
	cout << ans;
	
	return 0;
}