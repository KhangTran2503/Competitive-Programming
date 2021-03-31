#include <bits/stdc++.h>
#define all(s) (s).begin(), (s).end()
using namespace std;
typedef long long ll;
const ll INF = (ll)(1e18);
int n, m;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	vector<ll> H(n);
	vector<ll> W(m);
	
	for (ll &hi: H) cin >> hi;
	for (ll &wi: W) cin >> wi;
	
	sort(all(H));
	//sort(all(W));
	
	vector<ll> prefix((n >> 1) + 1), suffix((n >> 1) + 1);
	
	prefix[1] = abs(H[0] - H[1]);
	suffix[1] = abs(H[n - 1] - H[n - 1 - 1]);
	for (int i = 1; i < n/2; i ++){
		prefix[i + 1] = prefix[i] + abs(H[2*i] - H[2*i + 1]);
		suffix[i + 1] = suffix[i] + abs(H[n - 1 - 2*i] - H[n - 2 - 2*i]);
	} 

	ll ans = INF;
	for (ll wi: W){
		int pos = upper_bound(all(H),wi) - H.begin();
		//cout << pos << ' ';
		ll sum = 0;
		if ((pos & 1) == 0) sum = (prefix[pos/2] + abs(H[pos] - wi) + suffix[(n - pos)/2]);
		else sum = (abs(H[pos - 1] - wi) + prefix[(pos - 1)/2] + suffix[(n - pos)/2]);
		//cout << sum << '\n';
		ans = min(ans,sum);
	}
	cout << ans;
	return 0;
}
