/*	2021-06-10	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
ll memo[12][2][11];
ll pw10[12];
ll l, r;

ll dp(int pos,int low,int nine,ll x){
	if (pos == 0) return (ll)(nine + 1);
	ll &res = memo[pos][low][nine];
	if (res != -1) return res;
	
	int cur_d = (x/pw10[pos - 1]) % 10;
	int max_d = (low) ? 9 : cur_d;
	res = 0;
	for (int i = 0; i <= max_d; i++){
		int new_nine;
		if (i == 9) new_nine = nine + 1;
		else new_nine = 0;
		res += dp(pos - 1,low || (i < max_d),new_nine,x);
	}
	return res;
}


void solve(){
	cin >> l >> r;
	memset(memo,-1,sizeof(memo));
	
	ll ans_r = dp(11,0,0,r - 1);
	//cout << ans_r << ' ';
	memset(memo,-1,sizeof(memo));
	
	ll ans_l = dp(11,0,0,l - 1);
	//cout << ans_l << ' ';
	cout << ans_r - ans_l << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int T = 1;
	cin >> T;
	
	pw10[0] = 1;
	for (int i = 1; i < 12; i++) pw10[i] = pw10[i - 1]*10LL;
	while (T--) solve();
	return 0;
}
