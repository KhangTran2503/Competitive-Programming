#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
map<int,ll> cnt;
string s;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	ll ans = 0;
	for (int i =0; i < n; i++){
		cin >> s;
		int mask = 0;
		for (char x: s)
			mask ^= (1 << (int)(x - 'a'));
		ans += (ll)cnt[mask];
		for (int bit = 25; bit >= 0; bit--)
			ans += (ll)cnt[mask^(1 << bit)];
		cnt[mask]++;
	}
	cout << ans;
	return 0;
}