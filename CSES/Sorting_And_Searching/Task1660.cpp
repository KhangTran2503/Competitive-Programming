#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x;

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> x;

	map<ll,int> d;
	d[0]++;
	ll sum = 0;
	ll ans = 0;
	for (int i = 0; i < n; i++){
		int ai;
		cin >> ai;
		sum += (ll)ai;
		if (sum >= x) ans += (ll)d[sum - x];
		d[sum]++;
	}
	cout << ans;
	return 0;
}
