/*	2021-06-07	 */
#include <bits/stdc++.h>
#define all(s) (s).begin(),(s).end()
#define rall(s) (s).rbegin(),(s).rend()
#define uni(s) (s).erase(unique(all(s)),(s).end())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
const int INF = (int)(1e9) + 10;
int n;

void solve(){
	cin >> n;
	vector<ll> freq(n + 1);
	ll sum_freq = 0;
	ll ans = 0;
	
	for (int i = 1; i <= n; i++){
		int x;
		cin >> x;
		ans += (sum_freq - freq[x])*(ll)(n - i + 1);
		sum_freq += (ll)(i);
		freq[x] += (ll)(i);
	}
	
	cout << ans << '\n';
	
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T = 1;
	cin >> T;
	while (T--) solve();
	return 0;
}
