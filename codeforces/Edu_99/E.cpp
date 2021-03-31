/*#####################
  #	@author:trankhang #
  #	2020-12-01		  #
  #####################*/
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const ll INF = (ll)(1e18);
vector<ll> x(4);
vector<ll> y(4);
vector<ll> cur_x(4);
vector<ll> cur_y(4);
vector<int> per(4);

ll calc(ll len){
	for (int i = 0; i < 4; i++){
			cur_x[i] = x[per[i]];
			cur_y[i] = y[per[i]];
		}
		cur_x[3] -= len;
		cur_x[2] -= len;
		cur_y[1] -= len;
		cur_y[2] -= len;
		sort(all(cur_x));
		sort(all(cur_y));
		ll ans = 0;
		for (int i = 0; i < 4; i++){
			ans += (ll)abs(cur_x[i] - cur_x[1]);
			ans += (ll)abs(cur_y[i] - cur_y[1]);
		}
		return ans;
}

void solve(){
	
	for (int i = 0; i < 4; i++) cin >> x[i] >> y[i];
	
	
	iota(all(per),0);
	
	ll ans = INF;
	do
	{
		ll lo = 0;
		ll hi = (ll)(1e9);
		while (lo < hi){
			ll mid = (lo + hi) >> 1;
			if (calc(mid) < calc(mid + 1)) hi = mid;
			else lo = mid + 1;
		}
		ans = min(ans,calc(lo));
	} while (next_permutation(all(per)));
	cout << ans << '\n';
	
	
}


int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	
	return 0;
}