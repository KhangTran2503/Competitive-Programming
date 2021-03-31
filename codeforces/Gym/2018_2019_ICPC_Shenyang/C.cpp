#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(int t){
	ll n, k, q;
	cin >> n >> k >> q;
	ll ans = 1;
	
	for (int i = 1; i <= min(k,n); i++)
		ans = (ans*(ll)i) % q;
	
	if (k < n){
		ll bonus = (1LL + k*(n - k) % q + (n - k)*(n - k - 1) % q) % q;
		ans = (ans*bonus) % q;
	}
	cout << "Case #" << t << ": " << ans << '\n';
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) solve(i);
	return 0;
}
