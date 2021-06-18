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

int n, l, r;

void solve(){
	vector<int> a;
	cin >> n >> l >> r;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1){
		cout << 0 << '\n';
		return;
	}
	
	sort(all(a));
	ll ans = 0;
	for (int i = 1; i < n; i++){
		int low = lower_bound(a.begin(),a.begin() + i,l - a[i]) - a.begin();
		int high = upper_bound(a.begin(),a.begin() + i,r - a[i]) - a.begin() - 1;
		//cout << low << ' ' << high << '\n';
		if (low <= high) ans += (ll)(high - low + 1);
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
